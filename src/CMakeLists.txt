add_library(2D-Figures STATIC
    # Header files
    "contracts/circle.hpp"
    "contracts/triangle.hpp"
    "contracts/figure.hpp"
    "contracts/stringConvertible.hpp"

    # Source files
    "entities/circle.cpp"
    "entities/triangle.cpp"

    # factory files
    #{
    # factory interfaces
    "factory/interfaces/figure_factory.hpp"
    "factory/interfaces/random_figure_factory.hpp"
    "factory/interfaces/stream_figure_fractory.hpp"

    #factory implemamentations
    "factory/implementations/random_figure_factory.cpp"
    "factory/implementations/stream_figure_fractory.cpp"

    #}

    #utility files
    "utilities/string_to_figure.hpp"
    "utilities/string_to_figure.cpp"

)

target_include_directories(
    2D-Figures
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
