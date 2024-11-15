//
// Created by trangnt on 10/11/2024.
//
#include "Tetris.h"

Tetris::Tetris(int rows, int columns) : rows(rows), columns(columns) {
    grid.resize(rows, std::vector<int>(columns, 0));
    spawnTetromino();
}

void Tetris::update() {
    // Game logic to move tetromino down and check for full rows
    clearFullRows();
}

void Tetris::spawnTetromino() {
    currentTetromino = Tetromino();
}

void Tetris::clearFullRows() {
    // Logic to clear full rows and shift remaining blocks down
}

