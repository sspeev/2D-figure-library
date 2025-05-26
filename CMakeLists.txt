cmake_minimum_required(VERSION 3.10)

project("Homework2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

include(CMakePrintHelpers)

cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(CMAKE_PREFIX_PATH)

include(CTest)


# Make Catch2 available
if(BUILD_TESTING)

    message(STATUS "Make Catch2 available...")
    add_subdirectory(${CMAKE_SOURCE_DIR}/tests/Catch2)

endif()

include_directories("src")
add_subdirectory(src)

# Add the main executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 2D-Figures)

if(BUILD_TESTING)
    add_subdirectory(tests)
    message(STATUS "Tests subdirectory added.")
    message(STATUS "Building tests...")
endif()