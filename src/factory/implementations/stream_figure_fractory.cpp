#include "factory/interfaces/stream_figure_fractory.hpp"
#include "contracts/figure.hpp"
#include "utilities/string_to_figure.hpp"
#include <istream>
#include <iostream>
#include <string>

stream_figure_fractory::stream_figure_fractory(std::istream& is)
    : input_stream(is)
{
}

figure* stream_figure_fractory::create() //override
{
    std::cout << "Enter figure description: ";
    std::string line;
    if (std::getline(input_stream, line)) {
        string_to_figure converter;
        return converter.create_from(line);
    }
    return nullptr;
}
