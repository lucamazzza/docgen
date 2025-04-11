cmake_minimum_required(VERSION 3.15)
project(dg VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dg src/main.cc src/cmds.cc src/export.cc src/utils.cc)

target_include_directories(dg PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS dg
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

set(CPACK_GENERATOR "DEB;RPM;")

include(FetchContent)
FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)
FetchContent_MakeAvailable(CLI11)

target_link_libraries(dg PRIVATE CLI11::CLI11)
