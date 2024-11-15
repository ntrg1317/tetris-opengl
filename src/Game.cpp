//
// Created by trangnt on 10/11/2024.
//
#include "Game.h"

Game::Game(int width, int height) : width(width), height(height), tetris(20, 10), renderer() {

}

void Game::run(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        tetris.update();
        renderer.render(tetris);

        glfwSwapBuffers(window);
    }
}

