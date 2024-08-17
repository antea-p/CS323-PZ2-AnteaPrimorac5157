#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include <string>
#include "PokemonMove.h"
#include "Pokemon.h"
#include "Inventory.h"
#include "FileRepository.h"

class Battle
{
private:
    Pokemon *player, *enemy;
    Inventory inventory;
    unsigned int highScore;
    FileRepository fileRepository;
    std::vector<std::string> pokemonNames;

    Pokemon *setUpPlayerPokemon();
    Pokemon *setUpEnemyPokemon();
    Pokemon *setUpPokemon(const std::string &name);
    void initializePokemonNames();

public:
    static const std::vector<PokemonMove *> RANDOM_MOVES;

    Battle();
    ~Battle();

    void askPlayerInput();

    template<typename T>
    void getPlayerChoice(const std::vector<T *> &usables);
    void usePlayerItem();
    void usePlayerMove();
    void useEnemyMove();
    void printStatusMessages() const;
    void endBattle();
    void startGameLoop();
};

#endif //BATTLE_H