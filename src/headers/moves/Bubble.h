#ifndef BUBBLE_H
#define BUBBLE_H

#include "../PokemonMove.h"

class Bubble : public PokemonMove
{
public:
    Bubble();

    std::string getName() const override;

protected:
    int getDamageAmount() const override;
    PokemonType getDamageType() const override;
    std::string getDamageMessage(const Pokemon &user, const Pokemon &target) const override;
};

#endif //BUBBLE_H