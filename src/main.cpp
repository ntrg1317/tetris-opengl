#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game.h"
#include "resourceManager.h"

#include <iostream>

// GLFW function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// The Width of the screen
const unsigned int SCREEN_WIDTH = 600;
// The height of the screen
const unsigned int SCREEN_HEIGHT = 800;

Game Tetris(SCREEN_WIDTH, SCREEN_HEIGHT);

bool updatable = true;
bool isPaused = false;
bool downpress = false;
float timestepInput = 0.1f;
float timestepUpdate = 0.5f;
int main(int argc, char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TETRIS", nullptr, nullptr);
    glfwMakeContextCurrent(window);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // initialize game
    // ---------------
    Tetris.Init();

    // deltaTime variables
    // -------------------
    float deltaTimeInput = 0.0f;
    float lastFrameInput = 0.0f;
    timestepInput = 0.1f;

    float deltaTimeUpdate = 0.0f;
    float lastFrameUpdate = 0.0f;
    timestepUpdate = 0.5f;

    while (!glfwWindowShouldClose(window))
    {
        // calculate delta time
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTimeInput = currentFrame - lastFrameInput;
        deltaTimeUpdate = currentFrame - lastFrameUpdate;
        glfwPollEvents();
        if (!downpress) {
            timestepUpdate = Tetris.getTimeUpdate();
        }
        if (updatable) {
            if (deltaTimeInput > timestepInput) {
                // manage user input
                // -----------------
                Tetris.ProcessInput();
                lastFrameInput = currentFrame;
                deltaTimeInput = 0.0f;
            }

            if (deltaTimeUpdate > timestepUpdate) {
                // update game state
                // -----------------
                Tetris.Update();
                lastFrameUpdate = currentFrame;
                deltaTimeUpdate = 0.0f;
            }
        }

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Tetris.Render();

        glfwSwapBuffers(window);
    }

    ResourceManager::Clear();

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            Tetris.Keys[key] = true;
        else if (action == GLFW_RELEASE)
            Tetris.Keys[key] = false;
    }
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        //fastertime
        std::cout << "downkey pressed" << std::endl;
        timestepInput = 0.1f;
        timestepUpdate = 0.05f;
        downpress = true;

    }
    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) {
        //fastertime
        std::cout << "downkey released" << std::endl;
        timestepInput = 0.1f;
        downpress = false;

    }
    if (key == GLFW_KEY_R && action == GLFW_RELEASE) {
        Tetris.resetGame();
    }
    if (key == GLFW_KEY_ENTER && action == GLFW_RELEASE) {
        updatable = !updatable;
    }
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}