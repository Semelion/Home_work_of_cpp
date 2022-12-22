cmake_minimum_required(VERSION 3.23)
project(test)

set(CMAKE_CXX_STANDARD 17)

#add_library(geom geom/geom.cpp geom/geom.hpp)

include_directories(.)
add_subdirectory(geom)

add_executable(test main.cpp)
add_executable(test2 m_c.cpp)

target_link_libraries(test geom)
target_link_libraries(test2 geom)