#include "contracts/stringConvertible.hpp"
#include <string>

class stringConvertible
{
    public:
        virtual std::string toString() const = 0;
        virtual ~stringConvertible() = default;
};