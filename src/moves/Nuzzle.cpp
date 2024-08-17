#include "../headers/Pokemon.h"
#include "../headers/moves/Nuzzle.h"

Nuzzle::Nuzzle()
{
    name = "Nuzzle";
}

std::string Nuzzle::getName() const
{
    return name;
}

int Nuzzle::getDamageAmount() const
{
    return 20;
}

PokemonType Nuzzle::getDamageType() const
{
    return PokemonType::ELECTRIC;
}

std::string Nuzzle::getDamageMessage(const Pokemon &user, const Pokemon &target) const
{
    return user.getName() + " nuzzled against " + target.getName() + " with electric cheeks!";
}