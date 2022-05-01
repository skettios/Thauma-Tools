cmake_minimum_required(VERSION 3.20)
project(Thaumaturge)

include_directories("${CMAKE_SOURCE_DIR}/Numina/include")

add_executable(Thaumaturge WIN32 Main.cpp)
target_link_libraries(Thaumaturge Numina NuminaMain)
