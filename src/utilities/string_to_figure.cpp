#include "utilities/string_to_figure.hpp"
#include "contracts/circle.hpp"
#include "contracts/triangle.hpp"
#include <sstream>
#include <string>

string_to_figure::string_to_figure() = default;

figure *string_to_figure::create_from(std::string representation)
{
    std::istringstream iss(representation);
    std::string figure_type;

    // Extract the figure type
    if (!(iss >> figure_type))
    {
        return nullptr;
    }

    try
    {
        if (figure_type == "circle")
        {
            double radius;
            if (iss >> radius && radius > 0)
            {
                return new circle(radius);
            }
        }
        else if (figure_type == "triangle")
        {
            double a, b, c;
            if (iss >> a >> b >> c)
            {
                return new triangle(a, b, c);
            }
        }
    }
    catch (const std::exception &)
    {
        return nullptr; // If an exception was thrown during creation, return nullptr
    }

    return nullptr; // If we reach here, the input was invalid
}