#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>

#include "PokemonType.h"

class PokemonMove;

class Pokemon
{
private:
    std::string name;
    int health;
    int maxHealth;
    PokemonType pokemonType;
    std::vector<PokemonMove*> pokemonMoves;

public:
    Pokemon(const std::string& name, int health, int maxHealth, PokemonType pokemonType,
            const std::vector<PokemonMove*>& pokemonMoves);
    ~Pokemon() = default;
    Pokemon(const Pokemon& other);
    Pokemon& operator=(const Pokemon& other);

    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    PokemonType getPokemonType() const;
    const std::vector<PokemonMove*>& getPokemonMoves() const;

    void setName(const std::string& newName);
    void setHealth(int newHealth);
    void setMaxHealth(int newMaxHealth);
    void setPokemonType(PokemonType newPokemonType);
    void setPokemonMoves(const std::vector<PokemonMove*>& newPokemonMoves);

    void addPokemonMove(PokemonMove* pokemonMove);
    std::string getStatusAsString() const;
    std::string getPokemonMovesAsString() const;
    std::string useMove(size_t moveIndex, Pokemon& target);
    bool isDefeated() const;
};

#endif //POKEMON_H
