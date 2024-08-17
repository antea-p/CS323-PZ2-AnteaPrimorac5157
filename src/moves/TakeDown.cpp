#include "../headers/Pokemon.h"
#include "../headers/moves/TakeDown.h"

TakeDown::TakeDown()
{
    name = "Take Down";
}

std::string TakeDown::getName() const
{
    return name;
}

int TakeDown::getDamageAmount() const
{
    return 60;
}

PokemonType TakeDown::getDamageType() const
{
    return PokemonType::NORMAL;
}

std::string TakeDown::getDamageMessage(const Pokemon &user, const Pokemon &target) const
{
    return user.getName() + " slammed into " + target.getName() + " with full force!";
}

std::string TakeDown::use(Pokemon &user, Pokemon &target)
{
    std::string info = PokemonMove::use(user, target);
    int recoilDamage = getDamageAmount() / 2;
    info += "\n" + user.getName() + " takes " + std::to_string(recoilDamage) + " recoil damage!";
    user.setHealth(user.getHealth() - recoilDamage);
    return info;
}