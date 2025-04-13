cmake_minimum_required(VERSION 3.15)
project(dg VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)

add_executable(dg src/main.cc src/cmds.cc src/export.cc src/utils.cc src/const.cc)

target_include_directories(dg PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS dg
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

set(CPACK_GENERATOR "DEB;RPM;")
