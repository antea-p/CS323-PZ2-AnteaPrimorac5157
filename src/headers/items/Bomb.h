
#ifndef BOMB_H
#define BOMB_H
#include <Item.h>

class Bomb : public Item {
public:
    explicit Bomb(int quantity)
        : Item(quantity)
    {
    }

    ~Bomb() override = default;

    Bomb(const Bomb& other) = default;

    Bomb& operator=(const Bomb& other)
    {
        if (this == &other)
            return *this;
        Item::operator =(other);
        return *this;
    }

    virtual std::string getName() const override;

protected:
    virtual std::string useInternal(Pokemon& user, Pokemon& target) override;

};



#endif //BOMB_H
