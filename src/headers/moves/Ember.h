#ifndef EMBER_H
#define EMBER_H
#include "../PokemonMove.h"

class Ember : public PokemonMove
{
public:
    Ember() : PokemonMove() {}

    virtual std::string getName() const override;
    virtual std::string use(Pokemon& user, Pokemon& target) override;
};

#endif //EMBER_H
