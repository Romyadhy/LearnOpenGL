cmake_minimum_required(VERSION 3.16)

project(OPENGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(glad libs/glad/src/glad.c)

target_include_directories(glad PUBLIC
  libs/glad/include
)

add_executable(app src/main.cpp)
add_executable(shader src/shaders.cpp)

#app inlcude libs
target_include_directories(app PRIVATE
      libs/glfw/include
    )
target_link_directories(app PRIVATE
      libs/glfw/lib-mingw-w64
    )
target_link_libraries(app
    glfw3
    opengl32
    glad
)
#shaders include libs
target_include_directories(shader PRIVATE libs/glfw/include)
target_link_directories(shader PRIVATE libs/glfw/lib-mingw-w64)
target_link_libraries(shader glfw3 opengl32 glad)




