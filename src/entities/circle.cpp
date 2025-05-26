#include "contracts/circle.hpp"
#include <sstream>
#include <string>
#include <iostream>
#define PI 3.14159265358979323846

circle::circle() = default;

circle::circle(const char *input)
    : radius(), length()
{
    try
    {
        if (!input || !input[0])
            throw std::invalid_argument("Invalid input: Input is null or empty");

        std::stringstream ss(input);
        double radius;
        std::string type;

        if (!(ss >> type) || type != "triangle")
            throw std::invalid_argument("Invalid input: Missing or incorrect shape type");

        if (!(ss >> radius))
            throw std::invalid_argument("Invalid input: Missing radius");

        std::string extraData;
        if (ss >> extraData)
            throw std::invalid_argument("Invalid input: Extra unexpected data found");

        if (radius <= 0)
            throw std::invalid_argument("Invalid input: Radius must be positive");

        setRadius(radius);
        perimeter();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        radius = length = 0;
    }
}

void circle::setRadius(double input)
{
    radius = input;
}

double circle::perimeter() const //override
{
    return length;
}

std::string circle::toString() const //override
{
    std::ostringstream oss;
    oss << "circle" << radius;
    return oss.str();
}

double circle::calcLength()
{
    return PI * radius;
}
