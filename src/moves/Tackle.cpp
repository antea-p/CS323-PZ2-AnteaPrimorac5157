#include "../headers/Pokemon.h"
#include "../headers/moves/Tackle.h"


std::string Tackle::getName() const
{
    return "Tackle";
}


std::string Tackle::use(Pokemon& user, Pokemon& target)
{
    target.setHealth(target.getHealth() - 30);
    return user.getName() + " tackled " + target.getName() + " head-on!";
}