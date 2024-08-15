#include "Inventory.h"
#include "items/Potion.h"
#include "items/Bomb.h"
#include <sstream>
#include <time.h>

Inventory::~Inventory() {
    for (Item* item : items) {
        delete item;
    }
}

const std::vector<Item *>& Inventory::getItems() const {
    return items;
}

void Inventory::setItems(const std::vector<Item *>& newItems) {
    items = newItems;
}

void Inventory::generateInventory() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int potionQuantity = rand() % 4;
    int bombQuantity = rand() % 4;

    if (potionQuantity > 0) {
        items.push_back(new Potion(potionQuantity));
    }
    if (bombQuantity > 0) {
        items.push_back(new Bomb(bombQuantity));
    }
}

std::string Inventory::getItemsString() const {
    if (isEmpty()) {
        return "The inventory is empty.\n";
    }

    std::string result;
    std::vector<Item*>::const_iterator it;
    size_t index = 1;
    for (it = items.begin(); it != items.end(); ++it, ++index) {
        int quantity = (*it)->getQuantity();
        if (quantity > 0) {
            result += "Item #" + std::to_string(index) + ": " + (*it)->getName()
            + ", Quantity: " + std::to_string((*it)->getQuantity()) + "\n";
        }
    }
    return result;
}

bool Inventory::isEmpty() const {
    return items.empty() || (items.size() == 1 && items[0]->getQuantity() == 0);
}