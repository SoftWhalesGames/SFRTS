
add_library(GameApp GameApp.cpp)

target_link_libraries(
    GameApp
    PRIVATE
    sfml-graphics
    Animation
    Animator
)
