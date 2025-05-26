#include "contracts/figure.hpp"

class circle : public figure
{
private:
    double radius;
    double length;

    double calcLength();
    void setRadius(double input);

public:
    circle();
    circle(const char *input);
    //~circle();
    double perimeter() const override;
    // char* toString();
};
