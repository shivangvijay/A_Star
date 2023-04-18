cmake_minimum_required(VERSION 3.5)

project(Miko)
include_directories(include)

add_executable(Explore src/main.cpp src/Exploration.cpp src/Workspace.cpp src/Waypoints.cpp)