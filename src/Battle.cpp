#include <iostream>
#include <set>
#include <limits>
#include "Battle.h"
#include "exceptions/InvalidChoiceException.h"
#include "headers/moves/Ember.h"
#include "headers/moves/Tackle.h"
#include "headers/moves/Nuzzle.h"
#include "headers/moves/TakeDown.h"
#include "headers/moves/VineWhip.h"
#include "headers/moves/Bubble.h"

const std::vector<PokemonMove *> Battle::RANDOM_MOVES = {
        new Ember(), new Tackle(), new TakeDown(), new Bubble(), new Nuzzle(), new VineWhip()
};

Battle::Battle() :
    player(nullptr),
    enemy(nullptr),
    fileRepository("score.txt", "pokemon-list-en.txt")
{
    srand(static_cast<unsigned int>(time(nullptr)));

    initializePokemonNames();
    player = setUpPlayerPokemon();
    enemy = setUpEnemyPokemon();
    inventory.generateInventory();
    highScore = fileRepository.readScore();
}

Battle::~Battle() {
    delete player;
    delete enemy;
    for (PokemonMove *pokemonMove: RANDOM_MOVES) {
        delete pokemonMove;
    }
}


void Battle::initializePokemonNames() {
    std::set<std::string> pokemonSet = fileRepository.readAllPokemonSpecies();
    pokemonNames.assign(pokemonSet.begin(), pokemonSet.end());
}


void Battle::askPlayerInput() {
    int menuChoice;
    if (inventory.isEmpty()) {
        std::cout << "1) Use move" << std::endl;
        if (!(std::cin >> menuChoice) || (menuChoice != 1)) {
            throw InvalidChoiceException();
        }
        usePlayerMove();
    } else {
        std::cout << "Enter choice (1-2): \n 1) Use move \n 2) Use item" << std::endl;
        if (!(std::cin >> menuChoice) || (menuChoice != 1 && menuChoice != 2)) {
            throw InvalidChoiceException();
        }
        if (menuChoice == 1) {
            usePlayerMove();
        } else { // menuChoice == 2
            usePlayerItem();
        }
    }
}

template<typename T>
void Battle::getPlayerChoice(const std::vector<T *> &usables) {
    int choice;
    std::cout << "Enter choice:" << std::endl;
    for (int i = 0; i < usables.size(); ++i) {
        // primjer formata poruke ispod: ` 1) Potion`
        std::string message(" " + std::to_string(i + 1) + ") " + usables[i]->getName());
        std::cout << message << "\n";
    }

    // Ako nije procitan izbor, ili ako je negativan broj, ili veci od broja elemenata u usables vectoru
    if (!(std::cin >> choice) || choice < 1 || choice > static_cast<int>(usables.size())) {
        throw InvalidChoiceException();
    }

    std::cout << "PLAYER ACTION: " + usables[choice - 1]->use(*player, *enemy) << std::endl;
}

void Battle::usePlayerItem() {
    getPlayerChoice(std::vector<Usable *>(inventory.getItems().begin(), inventory.getItems().end()));
}

void Battle::usePlayerMove() {
    getPlayerChoice(std::vector<Usable *>(player->getPokemonMoves().begin(), player->getPokemonMoves().end()));
}

void Battle::useEnemyMove() {
    int enemyMoveChoice = rand() % (enemy->getPokemonMoves().size());
    std::cout << "ENEMY ACTION: " + enemy->useMove(enemyMoveChoice, *player);
}

Pokemon *Battle::setUpPlayerPokemon() {
    std::string name;
    std::cout << "Enter Pokemon name: ";
    if (!(std::cin >> name) || name.empty()) {
        throw std::runtime_error("Couldn't read the input! Make sure the name isn't empty!");
    }
    return setUpPokemon(name);
}

Pokemon *Battle::setUpEnemyPokemon() {
    int nameChoice = rand() % pokemonNames.size();
    return setUpPokemon(pokemonNames[nameChoice]);
};

Pokemon *Battle::setUpPokemon(const std::string &name) {
    int typeChoice = rand() % static_cast<int>(PokemonType::COUNT);
    auto pokemonType = static_cast<PokemonType>(typeChoice);

    int health = (rand() % 351) + 10;

    const int maxMovesSlots = 4;
    const int totalMovesCount = Battle::RANDOM_MOVES.size();
    std::vector<PokemonMove *> pokemonMoves;
    std::set<int> seen;

    for (int i = 0; i < std::min(maxMovesSlots, totalMovesCount); ++i) {
        int choice;
        do {
            choice = rand() % totalMovesCount;
            //  second je bool vrijednost koja ukazuje da li je element umetnut
        } while (!seen.insert(choice).second);
        pokemonMoves.push_back(Battle::RANDOM_MOVES[choice]);
    }

    return new Pokemon(name, health, health, pokemonType, pokemonMoves);
}

void Battle::printStatusMessages() const {
    std::cout << "\n------------------------" << std::endl;
    std::cout << "Player Pokemon status:" << std::endl;
    std::cout << player->getStatusAsString() << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Player Pokemon moves:" << std::endl;
    std::cout << player->getPokemonMovesAsString() << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Your inventory:" << std::endl;
    std::cout << inventory.getItemsString();
    std::cout << "------------------------" << std::endl;
    std::cout << "Enemy Pokemon status:" << std::endl;
    std::cout << enemy->getStatusAsString() << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Battle::endBattle() {
    if (enemy->isDefeated()) {
        std::cout << "\nEnemy defeated!" << std::endl;
        highScore++;
    } else if (player->isDefeated()) {
        std::cout << "\nSorry, you lose!" << std::endl;
        highScore = 0;
    }
    fileRepository.writeScore(highScore);
}

void Battle::startGameLoop() {
    std::cout << "Your high score: " << highScore;
    bool continueBattle = true;

    while (continueBattle && !enemy->isDefeated() && !player->isDefeated()) {
        try {
            printStatusMessages();
            askPlayerInput();
            useEnemyMove();
            inventory.removeUsedUpItems();
        } catch (const InvalidChoiceException &e) {
            std::cerr << e.what();
            std::cerr << " The turn will be skipped!";
            std::cin.clear(); // https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } catch (const std::logic_error &e) {
            std::cerr << e.what();
            std::cerr << " The turn will be skipped!" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
            continueBattle = false;  // Izadji iz petlje
        }
    }
    endBattle();
}