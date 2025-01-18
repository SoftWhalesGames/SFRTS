
# Головна програма
add_executable(${PROJECT_NAME} main.cpp)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


add_subdirectory(Animation)
add_subdirectory(Animator)
add_subdirectory(GameApp)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Animation
    Animator
    GameApp
    sfml-graphics
)
