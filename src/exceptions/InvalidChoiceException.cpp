#include "exceptions/InvalidChoiceException.h"

const char* InvalidChoiceException::what() const throw()
{
    return "Invalid choice input - likely a number out of range, or a letter. ";
}

