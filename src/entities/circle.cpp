#include "contracts/circle.hpp"
#include <sstream>
#include <string>
#define PI 3.14159265358979323846

circle::circle() = default;

circle::circle(const char *input)
    : radius(), length()
{
    std::stringstream ss(input);
    double radius;
    char* type = new char[10];

    

}
double circle::perimeter() const
{
    return length;
}

void circle::setRadius(double input)
{
    radius = input;
}

double circle::calcLength()
{
    return PI * radius;
}

// char* circle::toString()
// {
//     return new char[10];
// }