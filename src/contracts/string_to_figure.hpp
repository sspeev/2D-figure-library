#ifndef STRING_TO_FIGURE_HPP
#define STRING_TO_FIGURE_HPP
#include "contracts/figure.hpp"

class string_to_figure
{
public:
    string_to_figure();
    figure* create_from(std::string representation);
};


#endif