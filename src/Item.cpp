#include "headers/Item.h"

#include <stdexcept>

Item::Item(int quantity) : quantity(quantity) { }

int Item::getQuantity() const {
    return quantity;
}

int Item::setQuantity(int newQuantity) {
    quantity = newQuantity;
    return quantity;
}

bool Item::operator ==(const std::string &name) const {
    return this->getName() == name;
}

void Item::decrementQuantity() {
    if (quantity > 0) {
        --quantity;
    }
}

bool Item::isUsedUp() const {
    return quantity == 0;
}

std::string Item::use(Pokemon &user, Pokemon &target) {
    if (quantity < 1) {
        throw std::logic_error("Cannot use depleted item");
    }
    decrementQuantity();
    return useInternal(user, target);
}