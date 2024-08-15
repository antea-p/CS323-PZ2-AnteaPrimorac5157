#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <time.h>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item*> items;

public:
    Inventory() = default;
    Inventory(std::vector<Item *>& items) : items(items) {}

    virtual ~Inventory();

    const std::vector<Item *>& getItems() const;

    void setItems(const std::vector<Item *>& newItems);

    void generateInventory();
    std::string getItemsString() const;
    bool isEmpty() const;
};


#endif INVENTORY_H
