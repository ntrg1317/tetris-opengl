//
// Created by trangnt on 10/11/2024.
//

#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include "Tetris.h"
#include "Renderer.h"

class Game {
public:
    Game(int width, int height);
    void run(GLFWwindow* window);
private:
    int width, height;
    Tetris tetris;
    Renderer renderer;
};

#endif

