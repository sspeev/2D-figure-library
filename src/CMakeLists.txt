add_library(2D-Figures STATIC
    # Header files
    "contracts/circle.hpp"
    "contracts/triangle.hpp"
    "contracts/figure.hpp"

    # Source files
    #"entities/circle.cpp"
    "entities/triangle.cpp"
    #"entities/figure.cpp"
)

target_include_directories(
    2D-Figures
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_compile_features(
    2D-Figures
    PRIVATE
    cxx_std_17
)

set_target_properties(
    2D-Figures
    PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}"
)