# Executable target for the unit tests
add_executable(unit-tests)

target_link_libraries(
    unit-tests
    PRIVATE
    2D-Figures
    Catch2::Catch2WithMain
)

target_sources(
    unit-tests
    PRIVATE
    "triangle-tests.cpp"
)

# Include the Catch2 discovery module
include(Catch)

# Automatically register all tests
catch_discover_tests(unit-tests)