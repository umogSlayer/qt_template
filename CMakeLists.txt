cmake_minimum_required(VERSION 3.0)

project(GraphicsQtTemplate)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets)

set(APP_SOURCES
	src/main.cpp
	src/MainWindow.cpp
	src/MainWindow.h
	src/MainWindow.ui)

if(WIN32)
	add_executable(TemplateApp WIN32 ${APP_SOURCES})
else(WIN32)
	add_executable(TemplateApp ${APP_SOURCES})
endif(WIN32)

target_link_libraries(TemplateApp Qt5::Widgets)

if(WIN32)
	add_custom_command(
		TARGET TemplateApp POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$<TARGET_FILE:Qt5::Widgets>
			$<TARGET_FILE:Qt5::Core>
			$<TARGET_FILE:Qt5::Gui>
			$<TARGET_FILE_DIR:TemplateApp>)
endif(WIN32)