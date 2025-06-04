#include "factory/interfaces/figure_factory.hpp"
#include "factory/interfaces/random_figure_factory.hpp"
#include "factory/interfaces/stream_figure_fractory.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main()
{
    figure_factory *factory = nullptr;
    std::cout << "Welcome to 2D figure static library\n";
    std::cout << "How would you like your 2D figures to be generated:\n Randomly or ByStream[R/S]?\n";
    std::string key;
    std::cin >> key;
    if (key == "R")
    {
        factory = new random_figure_factory();
    }
    else if (key == "S")
    {
        factory = new stream_figure_fractory(std::cin);
        // Clear the input stream after reading the option
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cout << "Invalid option. Exiting.\n";
        return 1;
    }

    // Ask user how many figures to create
    int numFigures;
    std::cout << "How many figures would you like to create? ";
    std::cin >> numFigures;

    // Clear the input stream after reading the number
    if (key == "S")
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Create figures, display them and calculate total perimeter
    double totalPerimeter = 0.0;
    std::cout << "\nCreated figures:\n";

    for (int i = 0; i < numFigures; i++)
    {
        // Create a figure using the factory
        figure *currentFigure = factory->create();

        if (currentFigure)
        {
            // Display the figure
            std::cout << currentFigure->toString() << std::endl;

            // Add its perimeter to the total
            totalPerimeter += currentFigure->perimeter();

            // Clean up
            delete currentFigure;
        }
    }

    // Display total perimeter
    std::cout << "\nTotal perimeter of all figures: " << totalPerimeter << std::endl;

    // Clean up
    delete factory;
    return 0;
}