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
    # if(EXISTS ${CMAKE_SOURCE_DIR}/lib/Catch2)

    #     # If Catch2's repo has been cloned to the /lib directory, use that    
    #     add_subdirectory(${CMAKE_SOURCE_DIR}/lib/Catch2)

    # else()

    #     # Try to either find a local installation of Catch2,
    #     # or download it from its repository.
    #     #
    #     # You can find more information on how FetchContent works and
    #     # what is the order of locations being searched in these sources:
    #     #
    #     # Using Dependencies Guide
    #     #   https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#guide:Using%20Dependencies%20Guide
    #     # FetchContent examples:
    #     #   https://cmake.org/cmake/help/latest/module/FetchContent.html#fetchcontent-find-package-integration-examples
    #     # If necessary, set up FETCHCONTENT_TRY_FIND_PACKAGE_MODE. Check:
    #     #   https://cmake.org/cmake/help/latest/module/FetchContent.html#variable:FETCHCONTENT_TRY_FIND_PACKAGE_MODE
    #     # For Catch2's own documentation on CMake integration check:
    #     #   https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md

    #     include(FetchContent)

    #     # FIND_PACKAGE_ARGS makes it so that CMake first tries to find
    #     # CMake with find_package() and if it is NOT found, it will
    #     # be retrieved from its repository.
    #     FetchContent_Declare(
    #         Catch2
    #         GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    #         GIT_TAG v3.8.1
    #         FIND_PACKAGE_ARGS
    #     )

    #     FetchContent_MakeAvailable(Catch2)

    #     # The line below was necessary when Catch2 was obtained with FetchContent,
    #     # as described here:
    #     #   https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md)
    #     # This does not seem to be the case anymore.
    #     # list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

    # endif()
endif()

include_directories("src")
add_subdirectory(src)

if(BUILD_TESTING)
    add_subdirectory(tests)
    message(STATUS "Tests subdirectory added.")
    message(STATUS "Building tests...")
endif()