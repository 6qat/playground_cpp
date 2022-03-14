project(lab_module)
#set(CMAKE_CXX_FLAGS "/std:c++latest")

qt_add_library(lab_module STATIC)

# https://cmake.org/cmake/help/git-stage/command/cmake_policy.html#command:cmake_policy
cmake_policy(SET CMP0071 NEW)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
            STATUS
            "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake) # Include Conan-generated file
conan_check(REQUIRED) # Introduce Conan-generated targets
conan_cmake_run(
        REQUIRES
            range-v3/0.11.0
            protobuf/3.19.2
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
)

qt_add_executable(modern
        MANUAL_FINALIZATION
        modernCpp.cpp
        )
target_link_libraries(modern PRIVATE
        CONAN_PKG::range-v3
        CONAN_PKG::protobuf
        )

#qt_add_executable(ranges
#        MANUAL_FINALIZATION
#        ranges.cpp
#        )

qt_add_executable(rangev3
        MANUAL_FINALIZATION
        rangev3.cpp
        )


qt_add_qml_module(lab_module
        URI "lab"
        VERSION 1.0
        QML_FILES
            Other.qml
        SOURCES
            Lab.cpp Lab.h

        )
