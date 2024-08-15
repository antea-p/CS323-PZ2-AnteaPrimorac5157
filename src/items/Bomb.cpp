#include "../headers/items/Bomb.h"

#include <Pokemon.h>

std::string Bomb::getName() const
{
    return "Bomb";
}

std::string Bomb::useInternal(Pokemon& user, Pokemon& target)
{
    target.setHealth(target.getHealth() - 40);
    return std::string(user.getName() +  " throws a bomb at " +  target.getName()
        + ". It takes 40 damage!");
}
