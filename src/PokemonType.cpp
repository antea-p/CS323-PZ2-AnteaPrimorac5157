#include "headers/PokemonType.h"

#include <string>

std::string pokemonTypeToString(PokemonType type)
{
    switch(type) {
    case PokemonType::NORMAL: return "NORMAL";
    case PokemonType::ELECTRIC: return "ELECTRIC";
    case PokemonType::FIRE: return "FIRE";
    case PokemonType::WATER: return "WATER";
    case PokemonType::GRASS: return "GRASS";
    default: return "UNKNOWN";
    }
}

bool isSuperEffective(PokemonType attackerType, PokemonType targetType)
{
    switch (attackerType)
    {
    case PokemonType::ELECTRIC:
        return targetType == PokemonType::ELECTRIC;
    case PokemonType::FIRE:
        return targetType == PokemonType::GRASS;
    case PokemonType::WATER:
        return targetType == PokemonType::FIRE;
    case PokemonType::GRASS:
        return targetType == PokemonType::WATER;
    // vraca false za NORMAL i za neprepoznate tipove;
    // NORMAL nikad nije posebno efektivan
    default:
        return false;
    }

}


