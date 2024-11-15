//
// Created by trangnt on 10/11/2024.
//

#ifndef TETRIS_H
#define TETRIS_H

#include "Tetromino.h"
#include <vector>

class Tetris {
public:
    Tetris(int rows, int columns);
    void update();
    void spawnTetromino();
private:
    int rows, columns;
    Tetromino currentTetromino;
    std::vector<std::vector<int>> grid;
    void clearFullRows();
};

#endif

