#include "headers/Item.h"

#include <stdexcept>

Item::Item(int quantity) : quantity(quantity) {}

std::string Item::use(Pokemon& user, Pokemon& target)
{
    if (quantity < 1)
    {
        throw std::logic_error("There's nothing to decrement!");
    }
    --quantity;
    return useInternal(user, target);
}

int Item::getQuantity() const
{
    return quantity;
}

int Item::setQuantity(int newQuantity)
{
    quantity = newQuantity;
    return quantity;
}