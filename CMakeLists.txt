cmake_minimum_required (VERSION 3.15)
project(NeutralinoJS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_library(WEBKIT WebKit)

set(FRAMEWORK_FLAG -DWEBVIEW_COCOA=1)
set(LINK_OPTS ${WEBKIT})

file(GLOB SOURCES src/*.cc)
add_executable(neutralino ${SOURCES})
target_include_directories(neutralino PUBLIC thirdparty)

target_compile_options(neutralino PUBLIC ${FRAMEWORK_FLAG})
target_link_libraries(neutralino ${LINK_OPTS})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Configuring Release build")
    install(TARGETS neutralino DESTINATION ${CMAKE_SOURCE_DIR}/build)
endif()
