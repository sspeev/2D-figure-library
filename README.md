# C++ CMake Project

## Description
A C++ project built with CMake, providing a structured build system for cross-platform development. More specificaly the second Homework of the FMI-OOP Course

## Prerequisites
- CMake (version 3.10 or higher)
- C++ compiler (GCC, Clang, MSVC)

## Building the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Structure
```bash
project/
├── CMakeLists.txt                  # Root CMake file
├── README.md
├── src/
│   ├── CMakeLists.txt              # Source CMake file
│   ├── contracts/                  # Interface definitions
│   │   ├── figure.hpp              # Base figure interface
│   │   ├── circle.hpp              # Circle specification
│   │   └── other shape headers...  # Triangle, rectangle, etc.
│   ├── entities/                   # Concrete implementations
│   │   ├── circle.cpp              # Circle implementation
│   │   └── other shape implementations...
│   ├── factories/                  # Factory classes
│   │   ├── figure_factory.hpp      # Abstract factory interface
│   │   ├── concrete_factory.hpp    # Concrete factory implementation
│   │   └── concrete_factory.cpp
│   └── main.cpp                    # Application entry point
└── tests/
    ├── CMakeLists.txt              # Tests CMake file
    └── tests for the code
```
## Running
```bash
./bin/myproject
```

## Features
- Cross-platform build system
- Modular project structure
- Easy dependency management

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

## License
[MIT](https://choosealicense.com/licenses/mit/)