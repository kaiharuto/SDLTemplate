cmake_minimum_required(VERSION 3.10.0)
project(SDLTemplate VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(/opt/homebrew/Cellar/sdl3/3.2.14/include)
link_directories(/opt/homebrew/Cellar/sdl3/3.2.14/lib)

find_package(SDL3 REQUIRED)

target_link_libraries( ${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
)