#include <iostream>
#include <vector>

#include "headers/Pokemon.h"
#include "headers/PokemonMove.h"
#include "headers/PokemonType.h"
#include "headers/moves/Tackle.h"
#include "headers/items/Potion.h"


int main() {
    auto* tackle = new Tackle();
    std::vector<PokemonMove*> moves = {tackle};

    Pokemon pikachu("Pikachu", 100, 100, PokemonType::ELECTRIC, moves);
    Pokemon charmander("Charmander", 90, 90, PokemonType::FIRE, moves);

    std::cout << "Pikachu status:\n" << pikachu.getStatusAsString() << std::endl;
    std::cout << "Pikachu moves:\n" << pikachu.getPokemonMovesAsString() << std::endl;
    std::cout << "------------------------------" << std::endl;

    std::cout << pikachu.useMove(0, charmander) << std::endl;
    std::cout << "Charmander health: " << charmander.getHealth() << std::endl;
    std::cout << "------------------------------" << std::endl;

    Potion potion(3);
    std::cout << potion.use(charmander, charmander) << std::endl;
    std::cout << "Charmander health after potion: " << charmander.getHealth() << std::endl;
    std::cout << "------------------------------" << std::endl;

    Pokemon pikachu_copy = pikachu;
    std::cout << "Pikachu's copy status:\n" << pikachu_copy.getStatusAsString() << std::endl;
    std::cout << "------------------------------" << std::endl;

    Pokemon squirtle("Squirtle", 80, 80, PokemonType::WATER, moves);
    squirtle = charmander;
    std::cout << "Squirtle (assigned from Charmander) status:\n" << squirtle.getStatusAsString() << std::endl;
    std::cout << "------------------------------" << std::endl;

    delete tackle;

    return 0;
}
