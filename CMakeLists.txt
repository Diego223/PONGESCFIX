cmake_minimum_required(VERSION 3.21)

project(GAME VERSION 1.0)

# Enable C++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(SDL2, /Library/Frameworks/SDL2.framework)
set(glm_header_search_path /Library/Frameworks/glm/)
set(ENTT_INCLUDE_DIR /usr/local/Cellar/entt/3.12.2/include)
set(SOL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/home/os/Desktop/sol2/include/sol/)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find SDL_image library
# find_package(SDL2_image REQUIRED)
# include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(/home/os/Desktop/sol2/include)  # Replace /home/os/Desktop/sol2/ with the actual path to your sol2 directory
set(SDL2_IMAGE_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2_image.so")
find_package(Lua REQUIRED)

include_directories(${LUA_INCLUDE_DIR})
include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${glm_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${ENTT_INCLUDE_DIR}  
      ${SOL_INCLUDE_DIR}
          ${LUA_LIBRARIES}
)


add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Game/Game.cpp
    src/Pong/Pong.cpp
    src/Pong/Systems.cpp
    src/Scene/Scene.cpp  
)


target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${glm_header_search_path}
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/Game
    ${PROJECT_SOURCE_DIR}/src/Pong
    ${PROJECT_SOURCE_DIR}/src/Scene
    ${PROJECT_SOURCE_DIR}/src/ECS
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
# Find GLM
find_package(glm REQUIRED)

# Find SDL2 libraries
find_package(SDL2 REQUIRED)

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME}
  SDL2::SDL2main
  SDL2::SDL2
)
