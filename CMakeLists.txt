cmake_minimum_required(VERSION 3.5)

project(Playground_CPP VERSION 0.1 LANGUAGES CXX)

# -DCMAKE_TOOLCHAIN_FILE=D:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
# -DCMAKE_TOOLCHAIN_FILE=D:\dev\Qt\6.2.3\msvc2019_64\lib\cmake\Qt6\qt.toolchain.cmake

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest" "/interface" "/TP")
set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest" "/interface" "/TP")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")

#set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std=gnu++20")
#set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std=gnu++20")
# Edit file ~/.conan/profiles/mingw64 first.
# Create conanfile.txt in project root.
# conan install .. --build=missing --profile=mingw64
# cmake -G "MinGW Makefiles" ../

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 6.2 REQUIRED COMPONENTS Quick WebSockets Widgets QuickControls2)
#find_package(Protobuf CONFIG REQUIRED)
#find_package(Boost REQUIRED)

add_subdirectory(lab)
add_subdirectory(patterns)
add_subdirectory(Mastering-the-Cpp17-STL-master)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        ServerConnection.cpp
        ServerConnection.h
)

qt_add_executable(main
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
            STATUS
            "Downloading conan.cmake from https://raw.githubusercontent.com/conan-io/cmake-conan/develop/")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake) # Include Conan-generated file
conan_check(REQUIRED) # Introduce Conan-generated targets
conan_cmake_run(
        REQUIRES
        range-v3/0.11.0
        protobuf/3.19.2
        boost/1.78.0
        tomlplusplus/2.5.0
#        argparse/2.2
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
)

if( NOT EXISTS "${PROJECT_SOURCE_DIR}/toml.hpp")
    file(
            DOWNLOAD
            "https://raw.githubusercontent.com/marzer/tomlplusplus/v3.0.1/toml.hpp"
            "${PROJECT_SOURCE_DIR}/toml.hpp")
endif()

target_link_libraries(main PRIVATE
        lab_module   #plugin
#        CONAN_PKG::range-v3
        CONAN_PKG::protobuf
#        CONAN_PKG:tomlplusplus
#        CONAN_PKG::boost
#        protobuf::libprotobuf
#        Boost::boost
        )

target_link_libraries(main PRIVATE
        Qt6::Quick
        Qt6::WebSockets
        Qt6::Widgets
        Qt6::QuickControls2
        )

set_target_properties(main PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(main)

