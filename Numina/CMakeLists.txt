cmake_minimum_required(VERSION 3.20)
project(Numina)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB NUMINA_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.c")
list(FILTER NUMINA_SOURCES EXCLUDE REGEX "NuminaMain.cpp")
add_library(Numina SHARED "${NUMINA_SOURCES}")
add_library(NuminaMain STATIC "${PROJECT_SOURCE_DIR}/src/NuminaMain.cpp")

set_target_properties(Numina NuminaMain PROPERTIES DEBUG_POSTFIX "-d")

if(WIN32)
    target_compile_definitions(Numina PRIVATE TTN_PLATFORM_WIN32)
else()
    target_compile_definitions(Numina PRIVATE TTN_PLATFORM_LINUX)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(Numina PRIVATE TTN_DEBUG)
endif()

target_compile_definitions(Numina PRIVATE TTN_EXPORT)

target_link_libraries(Numina SDL2)
target_link_libraries(NuminaMain Numina SDL2 SDL2main)
