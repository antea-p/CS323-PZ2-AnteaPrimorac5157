#ifndef TACKLE_H
#define TACKLE_H
#include "../PokemonMove.h"

class Tackle : public PokemonMove
{
public:
    Tackle();

    std::string getName() const override;

protected:
    int getDamageAmount() const override;
    PokemonType getDamageType() const override;
    std::string getDamageMessage(const Pokemon& user, const Pokemon& target) const override;
};

#endif //TACKLE_H
