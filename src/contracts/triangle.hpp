#include "contracts/figure.hpp"

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
    triangle(const char *input);
    //~triangle();
    double perimeter() const override;
    char* toString();
};
