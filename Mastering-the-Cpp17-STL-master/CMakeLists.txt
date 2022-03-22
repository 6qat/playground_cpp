project(mastering_cpp)

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

add_executable(chapter01 Chapter01/examples-ch1.cc)
add_executable(chapter02 Chapter02/examples-ch2.cc)
add_executable(chapter03 Chapter03/examples-ch3.cc)
add_executable(chapter04 Chapter04/examples-ch4.cc)
add_executable(chapter05 Chapter05/examples-ch5.cc)
add_executable(chapter06 Chapter06/examples-ch6.cc)
add_executable(chapter07 Chapter07/examples-ch7.cc)
add_executable(chapter08 Chapter08/examples-ch8.cc)
add_executable(chapter09 Chapter09/examples-ch9.cc)
add_executable(chapter10 Chapter10/examples-ch10.cc)
add_executable(chapter11 Chapter11/examples-ch11.cc)
add_executable(chapter12 Chapter12/examples-ch12.cc)

target_link_libraries(chapter02 PRIVATE CONAN_PKG::boost)
target_link_libraries(chapter12 PRIVATE CONAN_PKG::boost)