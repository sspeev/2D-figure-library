#ifndef FIGURE_FACTORY_HPP
#define FIGURE_FACTORY_HPP
#include "contracts/figure.hpp"

class figure_factory
{
public:
    virtual figure *create() = 0;
    virtual ~figure_factory() = default;
};

#endif