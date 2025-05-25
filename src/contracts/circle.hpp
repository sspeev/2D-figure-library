class circle
{
private:
    double radius;
    double length;

    double calcLength();
    void setRadius(double input);
public:
    circle();
    circle(const char* input);
    ~circle();
    double getLength();
    //char* toString();
};
