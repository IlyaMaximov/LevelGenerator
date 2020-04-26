cmake_minimum_required(VERSION 3.15)
project(LevelGenerator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4.2 COMPONENTS graphics audio REQUIRED)

add_executable(LevelGenerator main.cpp LevelGenerator.h
        Managers/ClickManager.h Managers/SpaceManager.h
        GeomObjects/Button.cpp GeomObjects/Button.h GeomObjects/Minimap.h
        GeomObjects/Palette.h GeomObjects/TileMap.h Managers/MouseStatus.h Managers/MouseStatus.cpp)

target_link_libraries(LevelGenerator sfml-graphics sfml-window sfml-system)