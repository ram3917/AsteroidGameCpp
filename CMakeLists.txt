cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS} src)

#set(SOURCES src/*.cpp)
file(GLOB SOURCES "src/*.cpp")
add_executable(AsteroidShooter ${SOURCES})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(AsteroidShooter ${SDL2_LIBRARIES})

