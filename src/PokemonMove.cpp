#include "headers/PokemonMove.h"
#include "headers/Pokemon.h"

std::string PokemonMove::getName() const
{
    return name;
}

std::string PokemonMove::use(Pokemon &user, Pokemon &target) {
    PokemonType targetType = target.getPokemonType();
    bool superEffective = false;
    int damage = getDamageAmount();
    if (isSuperEffective(getDamageType(), targetType)) {
        damage *= 2;
        superEffective = true;
    }
    target.setHealth(target.getHealth() - damage);
    std::string message = getDamageMessage(user, target);
    return superEffective ? message + " It was super effective!" : message;
}

