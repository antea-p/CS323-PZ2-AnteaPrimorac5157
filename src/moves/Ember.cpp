#include <string>
#include "../headers/Pokemon.h"
#include "../headers/moves/Ember.h"

std::string Ember::getName() const
{
    return "Ember";
}

std::string Ember::use(Pokemon& user, Pokemon& target)
{
    target.setHealth(target.getHealth() - 20);
    return user.getName() + " enrobed " + target.getName() + " in flame!";
}
