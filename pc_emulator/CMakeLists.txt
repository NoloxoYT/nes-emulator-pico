cmake_minimum_required(VERSION 3.10)
project(NES_Emulator)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(nes_emulator main.cpp)
target_link_libraries(nes_emulator SDL2)