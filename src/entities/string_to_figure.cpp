#include "contracts/string_to_figure.hpp"
#include "contracts/figure.hpp"
#include "contracts/triangle.hpp"
#include "contracts/circle.hpp"

#include <string>
#include <sstream>

string_to_figure::string_to_figure() = default;

figure *string_to_figure::create_from(std::string representation)
{
    if (representation.empty())
        throw std::invalid_argument("Invalid input: Input is null or empty");
    
    std::istringstream iss(representation);
    std::string type;

    if (!(iss >> type) || type != "triangle" || type != "circle")
        throw std::invalid_argument("Invalid input: Missing or incorrect shape type");
        
    if (type == "triangle")
    {
        triangle *tri = new triangle(representation);
        return tri;
    }
    else if (type == "circle")
    {
        circle *circ = new circle(representation);
        return circ;
    }
}