cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

project(MKCDE LANGUAGES CXX)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.hpp"
    "src/*.inl"
    "src/*.cxx"
    "src/*.hxx"
    "src/*.ixx"
    "src/*.cc"
    "src/*.hh"
    "src/*.C"
    "src/*.H"
)
add_library(MKCDE ${SOURCES})
target_include_directories(MKCDE PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(MKCDE PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}
)
message(STATUS "Build configuration: ${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}")
