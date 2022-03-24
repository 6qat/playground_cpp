project(lab_module)
#set(CMAKE_CXX_FLAGS "/std:c++latest")

qt_add_library(lab_module STATIC)

# https://cmake.org/cmake/help/git-stage/command/cmake_policy.html#command:cmake_policy
cmake_policy(SET CMP0071 NEW)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
            STATUS
            "Downloading conan.cmake from https://raw.githubusercontent.com/conan-io/cmake-conan/develop/")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()
include(${CMAKE_BINARY_DIR}/conan.cmake) # Include Conan-generated file
conan_check(REQUIRED) # Introduce Conan-generated targets
conan_cmake_run(
        REQUIRES
        range-v3/0.11.0
        protobuf/3.19.2
        #            quickfix/1.15.1
        boost/1.78.0
        rxcpp/4.1.1
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
)

find_package(Qt6 6.2 REQUIRED COMPONENTS Widgets Core)

qt_add_executable(mylabclass
        MANUAL_FINALIZATION
        mylabclass.cpp mylabclass.h
        )
target_link_libraries(mylabclass PRIVATE
            Qt6::Widgets Qt6::Core
            )

qt_add_executable(const
        MANUAL_FINALIZATION
        constness.cpp
        )

qt_add_executable(modern
        MANUAL_FINALIZATION
        modernCpp.cpp
        )
target_link_libraries(modern
        PRIVATE
        CONAN_PKG::range-v3
        CONAN_PKG::protobuf
        )

qt_add_executable(reactive
        MANUAL_FINALIZATION
        reactive.cpp
        )
target_link_libraries(reactive
        PRIVATE
        CONAN_PKG::rxcpp
        )

qt_add_executable(cpp20
        MANUAL_FINALIZATION
        cpp20features.cpp
        )

qt_add_executable(ranges
        MANUAL_FINALIZATION
        ranges.cpp
        )

qt_add_executable(smart
        MANUAL_FINALIZATION
        smart-pointers.cpp
        )
target_link_libraries(smart
        PRIVATE
        CONAN_PKG::boost
        )

qt_add_executable(rangev3
        MANUAL_FINALIZATION
        rangev3.cpp
        )
target_link_libraries(rangev3
        PRIVATE
        CONAN_PKG::range-v3
        )

qt_add_executable(random
        MANUAL_FINALIZATION
        pseudo-random.cpp
        )

qt_add_executable(literals
        MANUAL_FINALIZATION
        literals.cpp
        )
target_link_libraries(literals
        PRIVATE
        CONAN_PKG::range-v3
        CONAN_PKG::boost
        )

qt_add_executable(stringview
        MANUAL_FINALIZATION
        string_view.cpp
        )

qt_add_qml_module(lab_module
        URI "lab"
        VERSION 1.0
        QML_FILES
#        Other.qml
        SOURCES
        Lab.cpp Lab.h

        )
