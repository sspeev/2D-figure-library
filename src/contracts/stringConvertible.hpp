#ifndef STRINGCONVERTIBLE_HPP
#define STRINGCONVERTIBLE_HPP
#include <string>

class stringConvertible
{
public:
    virtual std::string toString() const = 0;
    virtual ~stringConvertible() = default;
};

#endif