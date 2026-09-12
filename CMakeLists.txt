cmake_minimum_required(VERSION 4.0.0)

project(
		SnakeGame
		VERSION 1.0
		LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting up comile options
if(MSVC)
	add_compile_options(/W4 /WX) # /WX — treat warnings as errors
else()
	add_compile_options(-Wall -Wextra -Werror -Wpedantic -O2 -pedantic)
endif()

# Sources
set(SOURCES src/main.cpp src/Game.cpp src/Snake.cpp src/Food.cpp src/Field.cpp
												src/Renderer.cpp)

add_executable(snakeGame ${SOURCES})

install(TARGETS snakeGame RUNTIME DESTINATION bin)
