# Base image
FROM ubuntu:22.04

# Install build tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /src

# Copy only source files, headers, and build configuration
COPY src/ ./src/
COPY tests/ ./tests/
COPY CMakeLists.txt ./
COPY main.cpp ./

# Build the application
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build . --target Homework2

# Set the default command to run your executable
CMD ["./build/Homework2"]