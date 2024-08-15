#ifndef POTION_H
#define POTION_H
#include "../Item.h"

class Potion : public Item
{
public:
    explicit Potion(int quantity) : Item(quantity) {}

    std::string getName() const override;

protected:
    std::string useInternal(Pokemon& user, Pokemon& target) override;
};

#endif //POTION_H
