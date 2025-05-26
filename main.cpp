#include "factory/interfaces/figure_factory.hpp"
#include "factory/interfaces/random_figure_factory.hpp"
#include "factory/interfaces/stream_figure_fractory.hpp"
#include <iostream>
#include <string>

int main()
{
    figure_factory* factory = nullptr;
    std::cout << "Welcome to 2D figure static library\n";
    std::cout << "How would you like your 2D figures to be generated:\n Randomly or ByStream[R/S]?\n";
    std::string key;
    std::cin >> key;
    if (key == "R")
    {
        factory = new random_figure_factory();
    }
    else if(key == "S")
    {
        factory = new stream_figure_fractory(std::cin);
    }
    
    // Use factory here
    if (factory) {
        // Create a figure using the factory
        figure* my_figure = factory->create();
        
        delete my_figure;
    }
    
    // Don't forget to clean up
    delete factory;
    return 0;
}