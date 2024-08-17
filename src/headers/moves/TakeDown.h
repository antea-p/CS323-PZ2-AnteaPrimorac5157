#ifndef TAKEDOWN_H
#define TAKEDOWN_H

#include "../PokemonMove.h"

class TakeDown : public PokemonMove
{
public:
    TakeDown();

    std::string getName() const override;
    std::string use(Pokemon &user, Pokemon &target) override;

protected:
    int getDamageAmount() const override;
    PokemonType getDamageType() const override;
    std::string getDamageMessage(const Pokemon &user, const Pokemon &target) const override;
};

#endif //TAKEDOWN_H