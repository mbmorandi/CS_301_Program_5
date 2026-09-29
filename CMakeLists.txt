cmake_minimum_required(VERSION 3.10)
project(StackReverse CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StackReverse
	main.cpp
)

if(MSVC)
	target_compile_options(StackReverse PRIVATE /W4)
else()
	target_compile_options(StackReverse PRIVATE -Wall -Wextra)
endif()
