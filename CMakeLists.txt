cmake_minimum_required(VERSION 3.29)
project(HMT)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_C_STANDARD 11)

include_directories(.)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Add sources for GLAD
set(GLAD_SRC src/glad.c
#        src/input/InputHandler.cpp
#        src/input/InputHandler.h
)

add_executable(HMT
        main.cpp
#        src/Game.cpp
#        src/Tetris.cpp
#        src/Tetromino.cpp
#        src/Renderer.cpp
#        src/input/InputHandler.cpp
        ${GLAD_SRC}
        stb_image.h
)

target_include_directories(HMT PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(FetchContent)

FetchContent_Declare(
        glm
        GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

target_link_libraries(HMT
        glfw
        OpenGL::GL
        GLEW::GLEW
        glm::glm
        ${CMAKE_DL_LIBS}
)
