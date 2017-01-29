cmake_minimum_required(VERSION 3.0)

project(GraphicsQtTemplate)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets)

add_executable(TemplateApp src/main.cpp)

target_link_libraries(TemplateApp Qt5::Widgets)