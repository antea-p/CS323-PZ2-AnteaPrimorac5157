#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H
#include <string>

enum class PokemonType
{
    NORMAL,
    ELECTRIC,
    FIRE,
    WATER,
    GRASS
};

std::string pokemonTypeToString(PokemonType type);
bool isSuperEffective(PokemonType attackerType, PokemonType targetType);

#endif //POKEMONTYPE_H
