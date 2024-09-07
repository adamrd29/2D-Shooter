set(project "2D-Shooter")
set(SFML "SFML-2.5.1")

cmake_minimum_required(VERSION 3.23)
project(${project})

set(CMAKE_CXX_STANDARD 14)

add_executable(${project} src/main.cpp src/Player.cpp include/Player.h src/Base.cpp include/Base.h src/Enemy.cpp include/Enemy.h src/Bullet.cpp include/Bullet.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${SFML}/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${SFML}/include")
target_link_libraries(${project} sfml-system sfml-window sfml-graphics sfml-audio)