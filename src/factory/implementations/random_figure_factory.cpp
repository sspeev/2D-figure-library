#include "factory/interfaces/random_figure_factory.hpp"
#include "contracts/figure.hpp"
#include "contracts/circle.hpp"
#include "contracts/triangle.hpp"
#include "utilities/string_to_figure.hpp"
#include <random>
#include <string>
#include <sstream>
#include <cmath>

// Static random engine initialized once
static std::mt19937 generator{std::random_device{}()};

// Helper function to round to 2 decimal places
double roundToTwoDecimals(double value)
{
    return std::round(value * 100.0) / 100.0;
}

figure *random_figure_factory::create() // override
{
    std::uniform_int_distribution<int> figure_type_distribution(0, 1);
    int figure_type = figure_type_distribution(generator);
    std::uniform_real_distribution<double> param_distribution(1.0, 10.0);

    std::ostringstream oss;
    if (figure_type == 0)
    {
        // Create a circle with random radius
        double radius = roundToTwoDecimals(param_distribution(generator));
        oss << "circle " << radius;
    }
    else
    {
        // Create triangle with random sides
        double a = roundToTwoDecimals(param_distribution(generator));
        double b = roundToTwoDecimals(param_distribution(generator));

        // Calculate valid range for third side to satisfy triangle inequality
        double min_c = std::abs(a - b) + 0.1;
        double max_c = a + b - 0.1;

        // Generate random third side within valid range
        std::uniform_real_distribution<double> side_c_distribution(min_c, max_c);
        double c = roundToTwoDecimals(side_c_distribution(generator));

        oss << "triangle " << a << " " << b << " " << c;
    }

    string_to_figure converter;
    return converter.create_from(oss.str());
}