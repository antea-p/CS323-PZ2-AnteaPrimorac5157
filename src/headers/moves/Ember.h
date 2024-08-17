#ifndef EMBER_H
#define EMBER_H
#include "../PokemonMove.h"

class Ember : public PokemonMove
{
public:
    Ember();

    std::string getName() const override;

protected:
    int getDamageAmount() const override;
    PokemonType getDamageType() const override;
    std::string getDamageMessage(const Pokemon& user, const Pokemon& target) const override;
};

#endif //EMBER_H
