#ifndef INVALIDCHOICEEXCEPTION_H
#define INVALIDCHOICEEXCEPTION_H

#include <string>

class InvalidChoiceException
{
private:
    std::string errorMessage;
    InvalidChoiceException() {};

public:
    explicit InvalidChoiceException(const std::string &errorMessage)
    : errorMessage(errorMessage) {}

    const std::string &getErrorMessage() const;
};


#endif //INVALIDCHOICEEXCEPTION_H
