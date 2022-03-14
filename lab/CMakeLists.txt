project(lab_module)
#set(CMAKE_CXX_FLAGS "/std:c++latest")

qt_add_library(lab_module STATIC)

# https://cmake.org/cmake/help/git-stage/command/cmake_policy.html#command:cmake_policy
cmake_policy(SET CMP0071 NEW)

#qt_add_executable(modern
#        MANUAL_FINALIZATION
#        modernCpp.cpp
#        )
#qt_add_executable(ranges
#        MANUAL_FINALIZATION
#        ranges.cpp
#        )
#
#qt_add_executable(rangev3
#        MANUAL_FINALIZATION
#        rangev3.cpp
#        )


qt_add_qml_module(lab_module
        URI "lab"
        VERSION 1.0
        QML_FILES
            Other.qml
        SOURCES
            Lab.cpp Lab.h

        )
