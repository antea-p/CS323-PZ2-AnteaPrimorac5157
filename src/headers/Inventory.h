#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <time.h>
#include <algorithm>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item *> items;

public:
    Inventory() = default;
    ~Inventory();
    Inventory(const Inventory &other) = delete;
    Inventory &operator =(const Inventory &other) = delete;

    const std::vector<Item *> &getItems() const;
    void setItems(const std::vector<Item *> &newItems);

    void generateInventory();
    std::string getItemsString() const;
    bool isEmpty() const;
    Item *findItem(const std::string &itemName);

    void removeUsedUpItems();
};


#endif //INVENTORY_H
