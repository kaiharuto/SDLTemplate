cmake_minimum_required(VERSION 3.10.0)
project(SDLTemplate VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_OSX_ARCHITECTURES arm64)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")


add_subdirectory(include/SDL)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries( ${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
)



