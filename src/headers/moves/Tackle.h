#ifndef TACKLE_H
#define TACKLE_H
#include "../PokemonMove.h"

class Tackle : public PokemonMove
{
public:
    Tackle() : PokemonMove() {}

    virtual std::string getName() const override;
    virtual std::string use(Pokemon& user, Pokemon& target) override;
};

#endif //TACKLE_H
