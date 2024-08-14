#include "headers/PokemonType.h"

#include <string>

std::string pokemonTypeToString(PokemonType type)
{
    switch(type) {
    case PokemonType::NORMAL:
        return "NORMAL";
    case PokemonType::ELECTRIC:
        return "ELECTRIC";
    case PokemonType::FIRE:
        return "FIRE";
    case PokemonType::WATER:
        return "WATER";
    case PokemonType::GRASS:
        return "GRASS";
    default:
        return "UNKNOWN";
    }
}
