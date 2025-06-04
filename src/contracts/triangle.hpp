#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "contracts/figure.hpp"
#include <string>

class triangle : public figure
{
private:
    double perimeterField;
    double side1;
    double side2;
    double side3;

    void setSide1(double input);
    void setSide2(double input);
    void setSide3(double input);
    void setPerimeter();
    double calculatePerimeter();

public:
    triangle();
    triangle(const std::string input);
    triangle(double side_a, double side_b, double side_c);
    //~triangle();
    double perimeter() const override;
    std::string toString() const override;
};

#endif