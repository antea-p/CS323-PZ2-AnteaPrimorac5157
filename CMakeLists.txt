cmake_minimum_required(VERSION 3.28)
project(CS323_PZ2_AnteaPrimorac5157)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/src/headers)

file(GLOB_RECURSE SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/moves/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/items/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/exceptions/*.cpp"
)

file(GLOB_RECURSE HEADERS
        "${CMAKE_SOURCE_DIR}/src/headers/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})