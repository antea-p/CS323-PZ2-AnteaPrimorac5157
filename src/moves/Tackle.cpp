#include "../headers/Pokemon.h"
#include "../headers/moves/Tackle.h"

Tackle::Tackle()
{
    name = "Tackle";
}

std::string Tackle::getName() const
{
    return name;
}

int Tackle::getDamageAmount() const
{
    return 30;
}

PokemonType Tackle::getDamageType() const
{
    return PokemonType::NORMAL;
}

std::string Tackle::getDamageMessage(const Pokemon& user, const Pokemon& target) const
{
    return user.getName() + " tackled " + target.getName() + " head-on!";
}