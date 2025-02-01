add_library(ResourceManager ResourceManager.cpp)

target_link_libraries(ResourceManager
  PRIVATE
    sfml-graphics
)
