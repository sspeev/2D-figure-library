#include "factory/interfaces/random_figure_factory.hpp"
#include "contracts/figure.hpp"
#include "contracts/circle.hpp"
#include "contracts/triangle.hpp"
#include <cstdlib>  // for std::rand and std::srand
#include <ctime>    // for std::time
#include <string>
#include <sstream>

figure* random_figure_factory::create() //override
{
    // Seed the random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Randomly choose between circle (0) or triangle (1)
    int figure_type = std::rand() % 2;
    
    if (figure_type == 0) {
        // Create a circle with random radius between 1 and 10
        double radius = 1.0 + static_cast<double>(std::rand()) / RAND_MAX * 9.0;
        
        // Convert to string format for the constructor
        std::ostringstream oss;
        oss << "circle " << radius;
        return new circle(oss.str());
    }
    else {
        // Create triangle with random sides
        double a = 1.0 + static_cast<double>(std::rand()) / RAND_MAX * 9.0;
        double b = 1.0 + static_cast<double>(std::rand()) / RAND_MAX * 9.0;
        
        // Calculate valid range for third side to satisfy triangle inequality
        double min_c = std::abs(a - b) + 0.1;
        double max_c = a + b - 0.1;
        
        // Generate random third side
        double c = min_c + static_cast<double>(std::rand()) / RAND_MAX * (max_c - min_c);
        
        // Convert to string format for the constructor
        std::ostringstream oss;
        oss << "triangle " << a << " " << b << " " << c;
        return new triangle(oss.str());
    }
}