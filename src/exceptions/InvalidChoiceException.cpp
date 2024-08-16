#include "InvalidChoiceException.h"

const std::string &InvalidChoiceException::getErrorMessage() const {
    return errorMessage;
}
