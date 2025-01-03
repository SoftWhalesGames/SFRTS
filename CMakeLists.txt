cmake_minimum_required(VERSION 3.28)
project(SFRTS LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(src)
add_subdirectory(src)

# add_executable(${PROJECT_NAME})


# target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
