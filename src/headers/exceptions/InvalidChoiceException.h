#ifndef INVALIDCHOICEEXCEPTION_H
#define INVALIDCHOICEEXCEPTION_H

#include <string>
#include <exception>

struct InvalidChoiceException : public std::exception
{
    const char *what() const throw();
};

#endif //INVALIDCHOICEEXCEPTION_H
