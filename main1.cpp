#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Define the grid dimensions (10x20)
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 20;

// Function to initialize OpenGL
bool initializeGLFW() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed!" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Tetris Grid", NULL, NULL);
    if (!window) {
        std::cerr << "Window creation failed!" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD initialization failed!" << std::endl;
        return false;
    }
    return true;
}

// Function to set the projection matrix
void setProjection() {
    // Set the projection matrix to orthogonal
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Orthogonal projection
    glMatrixMode(GL_MODELVIEW);
}

// Function to render the Tetris grid
void renderGrid() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Define grid size
    float cellWidth = 2.0f / GRID_WIDTH;
    float cellHeight = 2.0f / GRID_HEIGHT;

    glColor3f(1.0f, 1.0f, 1.0f); // Set line color to white

    glBegin(GL_LINES);

    // Draw vertical grid lines
    for (int i = 0; i <= GRID_WIDTH; ++i) {
        float x = -1.0f + i * cellWidth;
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
    }

    // Draw horizontal grid lines
    for (int i = 0; i <= GRID_HEIGHT; ++i) {
        float y = -1.0f + i * cellHeight;
        glVertex2f(-1.0f, y);
        glVertex2f(1.0f, y);
    }

    glEnd();
}

int main() {
    if (!initializeGLFW()) {
        return -1;
    }

    GLFWwindow* window = glfwGetCurrentContext();

    // Set up OpenGL viewport and projection
    glViewport(0, 0, WIDTH, HEIGHT);
    setProjection();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the background color to black

    // Main game loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Render the grid
        renderGrid();

        // Swap buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
