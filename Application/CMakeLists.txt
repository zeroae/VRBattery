cmake_minimum_required(VERSION 3.1.0)
project(Application)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(batteryinfowidget batteryinfowidget.cpp)
target_link_libraries(batteryinfowidget Qt5::Widgets)

add_library(vroverlay openvroverlaycontroller.cpp)
target_link_libraries(vroverlay Qt5::Widgets openvr)

add_executable(VRBattery main.cpp)
target_link_libraries(VRBattery batteryinfowidget vroverlay )

install(TARGETS VRBattery 
        RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)

include(WinDeployQt)
WinDeployQt(TARGET VRBattery)
install(DIRECTORY ${PROJECT_BINARY_DIR}/windeployqt/
        DESTINATION bin)
