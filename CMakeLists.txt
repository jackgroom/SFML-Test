cmake_minimum_required(VERSION 3.23)
project(TestSFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestSFML main.cpp util/Vec2.h util/Vec2.cpp game/Circle.cpp game/Circle.h game/Game.cpp game/Game.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(TestSFML sfml-system sfml-window sfml-graphics sfml-audio)