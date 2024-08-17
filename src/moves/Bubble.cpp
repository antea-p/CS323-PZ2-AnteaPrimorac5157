#include "../headers/Pokemon.h"
#include "../headers/moves/Bubble.h"

Bubble::Bubble()
{
    name = "Bubble";
}

std::string Bubble::getName() const
{
    return name;
}

int Bubble::getDamageAmount() const
{
    return 20;
}

PokemonType Bubble::getDamageType() const
{
    return PokemonType::WATER;
}

std::string Bubble::getDamageMessage(const Pokemon &user, const Pokemon &target) const
{
    return user.getName() + " blasted " + target.getName() + " with bubbles!";
}