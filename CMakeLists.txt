cmake_minimum_required(VERSION 3.20.0)
project(SDLTemplate VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL3 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")



add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory
          "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "${CMAKE_CURRENT_SOURCE_DIR}/hello.bmp"
          "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets/hello.bmp"
)


target_link_libraries( ${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
)

