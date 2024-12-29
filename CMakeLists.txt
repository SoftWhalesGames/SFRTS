cmake_minimum_required(VERSION 3.28)
project(SFRTS LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME})

add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
