#include "contracts/stringConvertible.hpp"

class figure : public stringConvertible
{
public:
    virtual double perimeter() const = 0;
    virtual ~figure() = default;
};