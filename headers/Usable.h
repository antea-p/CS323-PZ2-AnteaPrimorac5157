#ifndef USABLE_H
#define USABLE_H
#include <string>

class Pokemon;

class Usable
{
public:

    virtual ~Usable() = default;
    virtual std::string getName() const = 0;
    virtual std::string use(Pokemon& user, Pokemon& target) = 0;
};

#endif //USABLE_H
