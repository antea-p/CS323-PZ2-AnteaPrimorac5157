#ifndef POKEMON_MOVE_H
#define POKEMON_MOVE_H
#include <string>
#include "Usable.h"
#include "PokemonType.h"

class Pokemon;

class PokemonMove : public Usable
{
protected:
    std::string name;
    virtual int getDamageAmount() const = 0;
    virtual PokemonType getDamageType() const = 0;
    virtual std::string getDamageMessage(const Pokemon& user, const Pokemon& target) const = 0;

public:
    // https://stackoverflow.com/a/122174, https://stackoverflow.com/a/6502854
    PokemonMove() = default;
    virtual ~PokemonMove() override = default;

    std::string getName() const override;
    std::string use(Pokemon& user, Pokemon& target) override;
};

#endif //POKEMON_MOVE_H
