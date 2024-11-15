//
// Created by trangnt on 10/11/2024.
//

#include "Tetromino.h"

Tetromino::Tetromino(TetrominoType type) : type(type) {
    initializeShape();
}

void Tetromino::initializeShape() {
    switch (type) {
        case TetrominoType::I: shape = {{1, 1, 1, 1}}; break;
        case TetrominoType::O: shape = {{1, 1}, {1, 1}}; break;
        case TetrominoType::T: shape = {{0, 1, 0}, {1, 1, 1}}; break;
        case TetrominoType::S: shape = {{0, 1, 1}, {1, 1, 0}}; break;
        case TetrominoType::Z: shape = {{1, 1, 0}, {0, 1, 1}}; break;
        case TetrominoType::J: shape = {{1, 0, 0}, {1, 1, 1}}; break;
        case TetrominoType::L: shape = {{0, 0, 1}, {1, 1, 1}}; break;
    }
}

void Tetromino::rotate() {
}

const std::vector<std::vector<int> > &Tetromino::getShape() const {
    return shape;
}

