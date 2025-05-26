#ifndef RANDOM_FIGURE_FACTORY_HPP
#define RANDOM_FIGURE_FACTORY_HPP
#include "factory/interfaces/figure_factory.hpp"

class random_figure_factory : public figure_factory
{
public:
    figure *create() override;
};

#endif