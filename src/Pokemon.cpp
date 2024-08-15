#include "headers/Pokemon.h"
#include "headers/PokemonMove.h"

Pokemon::Pokemon(const std::string& name, int health, int maxHealth,
                 PokemonType pokemonType, const std::vector<PokemonMove*>& pokemonMoves)
    : name(name), health(health), maxHealth(maxHealth), pokemonType(pokemonType),
      pokemonMoves(pokemonMoves)
{
}

Pokemon::Pokemon(const Pokemon& other)
    : name(other.name), health(other.health), maxHealth(other.maxHealth),
      pokemonType(other.pokemonType), pokemonMoves(other.pokemonMoves)
{
}

Pokemon& Pokemon::operator=(const Pokemon& other)
{
    if (this != &other)
    {
        name = other.name;
        health = other.health;
        maxHealth = other.maxHealth;
        pokemonType = other.pokemonType;
        pokemonMoves = other.pokemonMoves;
    }
    return *this;
}

std::string Pokemon::getName() const
{
    return name;
}

int Pokemon::getHealth() const
{
    return health;
}

int Pokemon::getMaxHealth() const
{
    return maxHealth;
}

PokemonType Pokemon::getPokemonType() const
{
    return pokemonType;
}

const std::vector<PokemonMove*>& Pokemon::getPokemonMoves() const
{
    return pokemonMoves;
}

void Pokemon::setName(const std::string& newName)
{
    name = newName;
}

void Pokemon::setHealth(const int newHealth)
{
    health = newHealth;
}

void Pokemon::setMaxHealth(const int newMaxHealth)
{
    maxHealth = newMaxHealth;
}

void Pokemon::setPokemonType(const PokemonType newPokemonType)
{
    pokemonType = newPokemonType;
}

void Pokemon::setPokemonMoves(const std::vector<PokemonMove*>& newPokemonMoves)
{
    pokemonMoves = newPokemonMoves;
}

void Pokemon::addPokemonMove(PokemonMove* pokemonMove)
{
    if (pokemonMoves.size() < 4)
    {
        pokemonMoves.push_back(pokemonMove);
    }
    else
    {
        std::cout << "Your Pokemon can't have more than 4 moves!" << std::endl;
    }
}

std::string Pokemon::getStatusAsString() const
{
    return std::string("## " + name + " ##\n## Health: " + std::to_string(health) + "/" + std::to_string(maxHealth)
        + " ##\n## Type: " + pokemonTypeToString(pokemonType) + " ##");
}

std::string Pokemon::getPokemonMovesAsString() const
{
    std::string result;
    for (size_t i = 0; i < 4; ++i)
    {
        std::string moveName = (i < pokemonMoves.size()) ? pokemonMoves[i]->getName() : "-";
        result += std::to_string(i + 1) + ": " + moveName + "\t";
    }
    return result;
}

std::string Pokemon::useMove(size_t moveIndex, Pokemon& target)
{
    if (moveIndex < pokemonMoves.size())
    {
        return pokemonMoves[moveIndex]->use(*this, target);
    }
    return "Invalid move index!";
}

bool Pokemon::isDefeated() const
{
    return health <= 0;
}
