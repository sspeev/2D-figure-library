#ifndef FIGURE_HPP
#define FIGURE_HPP
#include "contracts/stringConvertible.hpp"

class figure : public stringConvertible
{
public:
    virtual double perimeter() const = 0;
    virtual ~figure() = default;
};

#endif