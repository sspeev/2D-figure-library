#include "contracts/figure.hpp"
#include <string>

class circle : public figure
{
private:
    double radius;
    double length;

    double calcLength();
    void setRadius(double input);

public:
    circle();
    circle(const std::string input);
    //~circle();
    double perimeter() const override;
    std::string toString() const override;
};
