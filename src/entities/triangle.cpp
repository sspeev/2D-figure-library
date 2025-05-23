#include "contracts/triangle.hpp"
#include <iostream>
#include <sstream>
#include <string>

triangle::triangle() = default;

triangle::triangle(const char *input)
{
    std::istringstream ss(input);
    char *type = new char[10];
    double side1, side2, side3;
    char space;
    ss >> type >> space >> side1 >> space >> side2 >> space >> side3;
    setSide1(side1);
    setSide2(side2);
    setSide3(side3);
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
    perimeter = calculatePerimeter();
}

double triangle::calculatePerimeter()
{
    return side1 + side2 + side3;
}