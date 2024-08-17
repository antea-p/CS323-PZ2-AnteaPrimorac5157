#ifndef NUZZLE_H
#define NUZZLE_H

#include "../PokemonMove.h"

class Nuzzle : public PokemonMove
{
public:
    Nuzzle();

    std::string getName() const override;

protected:
    int getDamageAmount() const override;
    PokemonType getDamageType() const override;
    std::string getDamageMessage(const Pokemon &user, const Pokemon &target) const override;
};

#endif //NUZZLE_H