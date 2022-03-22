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

add_executable(chapter1 Chapter01/examples-ch1.cc)
add_executable(chapter2 Chapter02/examples-ch2.cc)
add_executable(chapter3 Chapter03/examples-ch3.cc)
add_executable(chapter4 Chapter04/examples-ch4.cc)
add_executable(chapter5 Chapter05/examples-ch5.cc)
add_executable(chapter6 Chapter06/examples-ch6.cc)
add_executable(chapter7 Chapter07/examples-ch7.cc)
add_executable(chapter8 Chapter08/examples-ch8.cc)
add_executable(chapter9 Chapter09/examples-ch9.cc)
add_executable(chapter10 Chapter10/examples-ch10.cc)
add_executable(chapter11 Chapter11/examples-ch11.cc)
add_executable(chapter12 Chapter12/examples-ch12.cc)

target_link_libraries(chapter12 PRIVATE CONAN_PKG::boost)