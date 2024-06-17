cmake_minimum_required(VERSION 3.26)
project(ClothingSimulation)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(ClothingSimulation main.cpp
        Cloth.cpp
        Cloth.h
        Stick.cpp
        Stick.h
        Point.cpp
        Point.h
        definitions.h
        Mouse.cpp
        Mouse.h
)

target_link_libraries(ClothingSimulation sfml-system)
target_link_libraries(ClothingSimulation sfml-graphics)
target_link_libraries(ClothingSimulation sfml-window)