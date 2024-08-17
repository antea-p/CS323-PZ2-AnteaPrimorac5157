#include "../headers/Pokemon.h"
#include "../headers/moves/VineWhip.h"

VineWhip::VineWhip()
{
    name = "Vine Whip";
}

std::string VineWhip::getName() const
{
    return name;
}

int VineWhip::getDamageAmount() const
{
    return 20;
}

PokemonType VineWhip::getDamageType() const
{
    return PokemonType::GRASS;
}

std::string VineWhip::getDamageMessage(const Pokemon &user, const Pokemon &target) const
{
    return user.getName() + " whipped " + target.getName() + " with vines!";
}