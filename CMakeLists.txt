cmake_minimum_required(VERSION 3.16)
project(nesnor CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(nesnor STATIC
	src/bus.cpp
	src/cpu.cpp
)

target_include_directories(nesnor
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

add_executable(nesnor_app
	src/main.cpp
)

target_link_libraries(nesnor_app PRIVATE nesnor)
