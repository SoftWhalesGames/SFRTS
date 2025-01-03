
add_library(Animator Animator.cpp)

target_link_libraries(Animator
  PRIVATE
    sfml-graphics
    Animation
)
