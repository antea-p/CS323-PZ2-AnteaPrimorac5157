#ifndef BATTLE_H
#define BATTLE_H


#include <vector>
#include "PokemonMove.h"
#include "Pokemon.h"
#include "Inventory.h"

class Battle
{
private:
    Pokemon* player, *enemy;
    Inventory inventory;
    int highScore;

    Pokemon* setUpPlayerPokemon();
    Pokemon* setUpEnemyPokemon();
    Pokemon* setUpPokemon(const std::string& name);

public:
    static const std::vector<PokemonMove*> RANDOM_MOVES;
    static const std::vector<std::string> NAMES;

    Battle();
    ~Battle();

    void askPlayerInput();

    template<typename T>
    void getPlayerChoice(const std::vector<T *> & usables);
    void usePlayerItem();
    void usePlayerMove();
    void useEnemyMove();
    void printStatusMessages() const;
    void endBattle();
    void startGameLoop();
};


#endif //BATTLE_H
