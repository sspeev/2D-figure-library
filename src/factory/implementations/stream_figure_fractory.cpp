#include "factory/interfaces/stream_figure_factory.hpp"
#include "utilities/string_to_figure.hpp"
#include <string>

stream_figure_factory::stream_figure_factory(std::istream &istream)
    : input_stream(istream)
{
}

figure *stream_figure_factory::create()
{
    if (input_stream.eof())
    {
        return nullptr;
    }

    std::string line;
    if (!std::getline(input_stream, line))
    {
        return nullptr;
    }

    // Use string_to_figure to convert the line to a figure object
    string_to_figure converter;
    return converter.create_from(line);
    // If the line contains invalid figure parameters,
    // string_to_figure will return nullptr
}
