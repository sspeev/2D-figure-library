#include "factory/interfaces/stream_figure_fractory.hpp"
#include "contracts/figure.hpp"
#include "utilities/string_to_figure.hpp"  // Include the string_to_figure utility
#include <istream>
#include <string>

stream_figure_fractory::stream_figure_fractory(std::istream& is)
    : input_stream(is)
{
}

figure* stream_figure_fractory::create() //override
{
    std::string line;
    if (std::getline(input_stream, line)) {
        string_to_figure converter;
        return converter.create_from(line);
    }
    return nullptr;
}
