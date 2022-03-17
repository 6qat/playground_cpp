project(design_patterns)

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
            boost/1.78.0
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
)


qt_add_executable(patterns
        MANUAL_FINALIZATION
            patterns.cpp
        )
target_link_libraries(patterns
        PRIVATE
            CONAN_PKG::boost
        )

qt_add_executable(srp
        MANUAL_FINALIZATION
        srp.cpp
        )
target_link_libraries(srp
        PRIVATE
        CONAN_PKG::boost
        )

qt_add_executable(ocp
        MANUAL_FINALIZATION
        ocp.cpp
        )
target_link_libraries(ocp
        PRIVATE
        CONAN_PKG::boost
        )
