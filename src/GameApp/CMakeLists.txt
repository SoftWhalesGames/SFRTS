
add_library(GameApp GameApp.cpp)

target_link_libraries(GameApp
  PRIVATE
    sfml-graphics
  Animation
  Animator
)
# target_sources(${PROJECT_NAME} PRIVATE ${GameApp_src})