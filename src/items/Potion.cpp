#include "../headers/Pokemon.h"
#include "../headers/items/Potion.h"

std::string Potion::getName() const
{
    return "Potion";
}

std::string Potion::useInternal(Pokemon& user, Pokemon& /*target*/)
{
    user.setHealth(std::min(user.getHealth() + 20, user.getMaxHealth()));
    return user.getName() + " used a Potion and recovered 20 HP!";
}
