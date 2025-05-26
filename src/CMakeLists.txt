add_library(2D-Figures STATIC
    # Header files
    "contracts/circle.hpp"
    "contracts/triangle.hpp"
    "contracts/figure.hpp"
    "contracts/stringConvertible.hpp"

    # Source files
    "entities/circle.cpp"
    "entities/triangle.cpp"
)

target_include_directories(
    2D-Figures
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)