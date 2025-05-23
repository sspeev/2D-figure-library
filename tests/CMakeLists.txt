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
    "ucn_tests.cpp"
    "registration_plate_tests.cpp"
    "vehicle_register_tests.cpp"
)

# Include the Catch2 discovery module
include(Catch)

# Automatically register all tests
catch_discover_tests(unit-tests)