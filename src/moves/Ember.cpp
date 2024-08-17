#include <string>
#include "../headers/Pokemon.h"
#include "../headers/moves/Ember.h"

Ember::Ember()
{
    name = "Ember";
}

std::string Ember::getName() const
{
    return name;
}

int Ember::getDamageAmount() const
{
    return 20;
}

PokemonType Ember::getDamageType() const
{
    return PokemonType::FIRE;
}

std::string Ember::getDamageMessage(const Pokemon& user, const Pokemon& target) const
{
    return user.getName() + " enrobed " + target.getName() + " in flame!";
}