#ifndef POKEMON_MOVE_H
#define POKEMON_MOVE_H
#include <string>
#include "Usable.h"

class Pokemon;

class PokemonMove : public Usable
{
protected:
    std::string name;

public:
    // https://stackoverflow.com/a/122174, https://stackoverflow.com/a/6502854
    PokemonMove() = default;
    virtual ~PokemonMove() override = default;

    std::string getName() const override;
    std::string use(Pokemon& user, Pokemon& target) override = 0;
};

#endif //POKEMON_MOVE_H
