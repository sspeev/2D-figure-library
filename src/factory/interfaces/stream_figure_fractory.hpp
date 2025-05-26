#ifndef STREAM_FIGURE_FACTORY_HPP
#define STREAM_FIGURE_FACTORY_HPP
#include "factory/interfaces/figure_factory.hpp"
#include "contracts/figure.hpp"
#include <istream>

class stream_figure_fractory : public figure_factory
{
public:
    stream_figure_fractory(std::istream& stream);
    figure* create() override;

};

#endif