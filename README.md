# C++ CMake Project

## Description
A C++ project built with CMake, providing a structured build system for cross-platform development. More specificaly the second Homework of the FMI-OOP Course

## Prerequisites
- CMake (version 3.10 or higher)
- C++ compiler (GCC, Clang, MSVC)
- Catch2 testing library

## Building the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Structure
```bash
2D-FIGURE-LIBRARY/
├── .vscode/                        # VS Code configuration files
├── src/
│   ├── contracts/                  # Interface definitions
│   │   ├── figure.hpp              # Base figure interface
│   │   ├── string_convertible.hpp  # Interface for string conversion
│   │   ├── circle.hpp              # Circle specification
│   │   └── triangle.hpp            # Triangle specification
│   ├── entities/                   # Concrete implementations
│   │   ├── circle.cpp              # Circle implementation
│   │   └── triangle.cpp            # Triangle implementation
│   ├── factory/                    # Factory pattern implementations
│   │   ├── interfaces/             # Factory interfaces
│   │   │   ├── figure_factory.hpp  # Base factory interface
│   │   │   ├── random_figure_factory.hpp # Random figure factory
│   │   │   └── stream_figure_factory.hpp # Stream-based figure factory
│   │   └── implementations/        # Factory implementations
│   │       ├── random_figure_factory.cpp # Random figure generation
│   │       └── stream_figure_factory.cpp # Stream figure parsing
│   ├── utilities/                  # Utility classes and functions
│   │   └── string_to_figure.hpp    # String to figure conversion utility
│   └── CMakeLists.txt              # Source CMake file
├── tests/
│   ├── circle-tests.cpp            # Tests for circle class
│   ├── triangle-tests.cpp          # Tests for triangle class
│   ├── factory-tests.cpp           # Tests for factories
│   ├── string-conversion-tests.cpp # Tests for string conversion
│   └── CMakeLists.txt              # Tests CMake file
├── .gitignore                      # Git ignore file
├── CMakeLists.txt                  # Root CMake file
├── main.cpp                        # Application entry point
└── README.md                       # This file
```
## Running
```bash
./bin/myproject
```

## Features
- Modular project structure
- Easy dependency management

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

## Important
In order to run tests you need to download the official Catch2 library from [GitHub](https://github.com/catchorg/Catch2). After downloading the folder you need to rename it if it is something different from "Catch2". Then put it in tests folder. See project structure for more info