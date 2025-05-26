#include "factory/interfaces/random_figure_factory.hpp"
#include "contracts/figure.hpp"
#include "contracts/circle.hpp"
#include "contracts/triangle.hpp"
#include <random>
#include <string>
#include <sstream>

// Static random engine initialized once
static std::mt19937 generator{std::random_device{}()};

figure* random_figure_factory::create() //override
{
    // Choose between circle (0) or triangle (1) with equal probability
    std::uniform_int_distribution<int> figure_type_distribution(0, 1);
    int figure_type = figure_type_distribution(generator);
    
    // Random distribution for figure parameters between 1 and 10
    std::uniform_real_distribution<double> param_distribution(1.0, 10.0);
    
    if (figure_type == 0) {
        // Create a circle with random radius
        double radius = param_distribution(generator);
        
        // Convert to string format for the constructor
        std::ostringstream oss;
        oss << "circle " << radius;
        return new circle(oss.str());
    }
    else {
        // Create triangle with random sides
        double a = param_distribution(generator);
        double b = param_distribution(generator);
        
        // Calculate valid range for third side to satisfy triangle inequality
        double min_c = std::abs(a - b) + 0.1;
        double max_c = a + b - 0.1;
        
        // Generate random third side within valid range
        std::uniform_real_distribution<double> side_c_distribution(min_c, max_c);
        double c = side_c_distribution(generator);
        
        // Convert to string format for the constructor
        std::ostringstream oss;
        oss << "triangle " << a << " " << b << " " << c;
        return new triangle(oss.str());
    }
}