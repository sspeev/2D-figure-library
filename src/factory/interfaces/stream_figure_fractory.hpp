#ifndef STREAM_FIGURE_FACTORY_HPP
#define STREAM_FIGURE_FACTORY_HPP
#include "factory/interfaces/figure_factory.hpp"
#include <istream>

class stream_figure_fractory : public figure_factory {
private:
    std::istream& input_stream;

public:
    stream_figure_fractory(std::istream& is);
    figure* create() override;
};

#endif