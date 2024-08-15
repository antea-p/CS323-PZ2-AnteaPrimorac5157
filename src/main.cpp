#include <iostream>
#include <vector>

#include "headers/Pokemon.h"
#include "headers/PokemonMove.h"
#include "headers/PokemonType.h"
#include "headers/moves/Tackle.h"
#include "headers/items/Potion.h"
#include "Inventory.h"


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

    std::cout << "Testing Inventory:\n";
    std::cout << "------------------------------" << std::endl;

    Inventory inventory;
    inventory.generateInventory();
    std::cout << "Inventory items after generation:\n" << inventory.getItemsString() << std::endl;

    if (!inventory.getItems().empty()) {
        Item *item = inventory.getItems()[0];
        if (item->getName() == "Potion") {
            std::cout << item->use(charmander, charmander) << std::endl;
            std::cout << "Charmander health after using inventory Potion: " << charmander.getHealth() << std::endl;
        }
    }

    if (inventory.getItems().size() > 1) {
        Item *item = inventory.getItems()[1];
        if (item->getName() == "Bomb") {
            std::cout << item->use(pikachu, charmander) << std::endl;
            std::cout << "Charmander health after Bomb: " << charmander.getHealth() << std::endl;
        }
    }

    std::cout << "Updated inventory items:\n" << inventory.getItemsString() << std::endl;


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
