#include "contracts/triangle.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

triangle::triangle() = default;

triangle::triangle(const std::string input)
    : side1(0), side2(0), side3(0), perimeterField(0)
{
    try
    {
        if (input.empty())
            throw std::invalid_argument("Invalid input: Input is empty");

        std::istringstream ss(input);
        std::string type;
        double s1, s2, s3;

        if (!(ss >> s1))
            throw std::invalid_argument("Invalid input: Missing first side");

        if (!(ss >> s2))
            throw std::invalid_argument("Invalid input: Missing second side");

        if (!(ss >> s3))
            throw std::invalid_argument("Invalid input: Missing third side");

        std::string extraData;
        if (ss >> extraData)
            throw std::invalid_argument("Invalid input: Extra unexpected data found");

        if (s1 <= 0)
            throw std::invalid_argument("Invalid input: First side must be positive");
        if (s2 <= 0)
            throw std::invalid_argument("Invalid input: Second side must be positive");
        if (s3 <= 0)
            throw std::invalid_argument("Invalid input: Third side must be positive");

        if (s1 + s2 <= s3)
            throw std::invalid_argument("Invalid triangle: The sum of sides 1 and 2 must be greater than side 3");
        if (s1 + s3 <= s2)
            throw std::invalid_argument("Invalid triangle: The sum of sides 1 and 3 must be greater than side 2");
        if (s2 + s3 <= s1)
            throw std::invalid_argument("Invalid triangle: The sum of sides 2 and 3 must be greater than side 1");

        setSide1(s1);
        setSide2(s2);
        setSide3(s3);
        setPerimeter();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        side1 = side2 = side3 = perimeterField = 0;
    }
}

void triangle::setSide1(double input)
{
    side1 = input;
}

void triangle::setSide2(double input)
{
    side2 = input;
}

void triangle::setSide3(double input)
{
    side3 = input;
}

void triangle::setPerimeter()
{
    perimeterField = calculatePerimeter();
}

double triangle::perimeter() const // override
{
    return perimeterField;
}

std::string triangle::toString() const // override
{
    std::ostringstream oss;
    oss << "triangle" << " " << side1 << " " << side2 << " " << side3;

    return oss.str();
}

double triangle::calculatePerimeter()
{
    return side1 + side2 + side3;
}