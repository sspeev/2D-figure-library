
class triangle
{
private:
    double perimeter;
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
    ~triangle();
    double getPerimeter() const;
};
