#ifndef VINEWHIP_H
#define VINEWHIP_H
#include "../PokemonMove.h"

class VineWhip : public PokemonMove
{
public:
    VineWhip();

    std::string getName() const override;

protected:
    int getDamageAmount() const override;
    PokemonType getDamageType() const override;
    std::string getDamageMessage(const Pokemon &user, const Pokemon &target) const override;
};

#endif // VINEWHIP_H
