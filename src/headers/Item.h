#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Usable.h"

class Pokemon;

class Item : public Usable
{
private:
    int quantity;

protected:
    virtual std::string useInternal(Pokemon &user, Pokemon &target) = 0;

public:
    explicit Item(int quantity);
    virtual ~Item() override = default;

    virtual std::string getName() const override = 0;
    int getQuantity() const;
    int setQuantity(int newQuantity);
    bool operator ==(const std::string &name) const;

    void decrementQuantity();
    bool isUsedUp() const;

    virtual std::string use(Pokemon &user, Pokemon &target) override;
};

#endif //ITEM_H
