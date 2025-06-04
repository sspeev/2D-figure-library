#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "contracts/figure.hpp"
#include <string>

class circle : public figure
{
private:
    double radius;
    double length;

    double calcLength();
    void setRadius(double input);
    void setLength();

public:
    circle();
    circle(const std::string input);
    circle(double radius);
    //~circle();
    double perimeter() const override;
    std::string toString() const override;
};

#endif