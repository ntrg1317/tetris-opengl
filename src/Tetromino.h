//
// Created by trangnt on 10/11/2024.
//

#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>

enum class TetrominoType { I, O, T, S, Z, J, L };

class Tetromino {
public:
    Tetromino(TetrominoType type);
    void rotate();
    const std::vector<std::vector<int>>& getShape() const;

private:
    TetrominoType type;
    std::vector<std::vector<int>> shape;
    void initializeShape();
};

#endif
