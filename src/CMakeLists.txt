
# Головна програма
add_executable(${PROJECT_NAME} main.cpp)



set(SFML_VERSION 2.5.1)
set(IMGUI_VERSION 1.87)
include(FetchContent)

FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
   )
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG        v1.89
)

FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
  GIT_TAG        2.6.x

)


option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(sfml)

FetchContent_MakeAvailable(imgui)

set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" ON)

FetchContent_MakeAvailable(imgui-sfml)


add_subdirectory(Animation)
add_subdirectory(Animator)
add_subdirectory(GameApp)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Animation
    Animator
    GameApp
    ImGui-SFML::ImGui-SFML
   
)