#include <iostream>
#include <set>
#include "Battle.h"
#include "moves/Ember.h"
#include "moves/Tackle.h"
#include "exceptions/InvalidChoiceException.h"

// TODO: I/O, izuzeci
const std::vector<PokemonMove *> Battle::RANDOM_MOVES = {
    new Ember(), new Tackle()
};

const std::vector<std::string> Battle::NAMES = {
        "Charmander", "Bulbasaur", "Oddish", "Squirtle",
        "Vulpix", "Eevee", "Meowth", "Rattata",
        "Pidgey", "Jigglypuff", "Psyduck", "Staryu"
};

Battle::Battle() : player(nullptr), enemy(nullptr)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    player = setUpPlayerPokemon();
    enemy = setUpEnemyPokemon();
    inventory.generateInventory();
}

Battle::~Battle() {
    delete player;
    delete enemy;
    for (PokemonMove* pokemonMove: RANDOM_MOVES) {
        delete pokemonMove;
    }
}

void Battle::askPlayerInput() {
    int menuChoice;
    std::cout << "Enter choice (1-2): \n Use move \n 2) Use item" << std::endl;
    std::cin >> menuChoice;
    if (menuChoice == 1) {
        usePlayerMove();
    } else if (menuChoice == 2) {
        usePlayerItem();
    } else {
        std::cerr << "Invalid choice exception!" << std::endl;
    }
}

template<typename T>
void Battle::getPlayerChoice(const std::vector<T *> & usables) {
    int choice;
    std::cout << "Enter choice:" << std::endl;
    for (size_t i = 0; i < usables.size(); ++i) {
        // primjer formata poruke ispod: `1) Potion`
        std::cout << i + 1 << ") " << usables[i]->getName() << std::endl;
    }

    std::cin >> choice;
    if (choice < 1 || choice > usables.size()) {
        std::string result = usables[choice - 1]->use(*player, *enemy);
        std::cout << result << std::endl;
    } else {
        std::cerr << "Invalid choice exception!" << std::endl;
    }
}

void Battle::usePlayerItem() {
    getPlayerChoice(std::vector<Usable *>(inventory.getItems().begin(), inventory.getItems().end()));
}

void Battle::usePlayerMove() {
    getPlayerChoice(std::vector<Usable *>(player->getPokemonMoves().begin(), player->getPokemonMoves().end()));
}

void Battle::useEnemyMove() {
    int enemyMoveChoice = rand() % (enemy->getPokemonMoves().size());
    std::cout << "\n " + enemy->useMove(enemyMoveChoice, *player);
}

Pokemon* Battle::setUpPlayerPokemon() {
    std::string name;
    std::cout << "Enter Pokemon name:";
    std::cin >> name;
}

Pokemon* Battle::setUpEnemyPokemon() {
    int nameChoice = rand() & Battle::NAMES.size();
    return setUpPokemon(Battle::NAMES[nameChoice]);
};

Pokemon* setUpPokemon(const std::string& name) {
    int typeChoice = rand() % static_cast<int>(PokemonType::COUNT);
    PokemonType pokemonType = static_cast<PokemonType>(typeChoice);

    int health = (rand() % 351) + 150;

    // Koristenje seta sprecava move-ove duplikate
    std::vector<PokemonMove *> moves;
    std::set<int> seen;
    for (int i = 0; i < 4; i++) {
        int choice;
        do {
            choice = rand() % Battle::RANDOM_MOVES.size();
        } while (!seen.insert(choice).second);
        moves.push_back(Battle::RANDOM_MOVES[choice]);
    }

    return new Pokemon(name, health, health, pokemonType, moves);
}

void Battle::printStatusMessages() const {
    std::cout << "------------------------" << std::endl;
    std::cout << "Player Pokemon status:" << std::endl;
    std::cout << player->getStatusAsString() << std::endl;
    std::cout << player->getPokemonMovesAsString() << std::endl;
    std::cout << inventory.getItemsString();
    std::cout << "------------------------" << std::endl;
    std::cout << "Enemy Pokemon status:" << std::endl;
    std::cout << enemy->getStatusAsString() << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Battle::endBattle() {
    if (enemy->isDefeated()) {
        std::cout << "Enemy defeated!" << std::endl;
        highScore++;
    } else if (player->isDefeated()) {
        std::cout << "Sorry, you lose!" << std::endl;
        highScore = 0;
    }
    // TODO: file I/O
}

void Battle::startGameLoop() {
    // TODO: file I/O 
    std::cout << "Your high score: " << highScore << std::endl;
    do {
        try {
            printStatusMessages();
            askPlayerInput();
            useEnemyMove();
        } catch (const InvalidChoiceException &) {
            std::cerr << "~~~~~~~~~~~~~~~~~~~~~~\n"
                      << "Invalid choice number!\n"
                      << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
        }
    } while (!enemy->isDefeated() && !player->isDefeated());
    endBattle();
}