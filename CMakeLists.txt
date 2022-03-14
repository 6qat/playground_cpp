cmake_minimum_required(VERSION 3.5)

project(Tapechart_Qt VERSION 0.1 LANGUAGES CXX)

# -DCMAKE_TOOLCHAIN_FILE=D:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest" "/interface" "/TP")
#set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest" "/interface" "/TP")
#set(CMAKE_CXX_FLAGS "-std:c++latest /interface /TP")
#set(CMAKE_CXX_FLAGS "/std:c++latest")

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick WebSockets Widgets QuickControls2)
#find_package(Protobuf CONFIG REQUIRED)
#find_package(Boost REQUIRED)

add_subdirectory(lab)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        ServerConnection.cpp
        ServerConnection.h
)

qt_add_executable(temp_qt
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(temp_qt PRIVATE
        lab_module   #plugin
#        protobuf::libprotobuf
#        Boost::boost
        )

target_link_libraries(temp_qt PRIVATE
        Qt6::Quick
        Qt6::WebSockets
        Qt6::Widgets
        Qt6::QuickControls2
        )

set_target_properties(temp_qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(temp_qt)

