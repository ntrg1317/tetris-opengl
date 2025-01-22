//
// Created by trangnt on 18/11/2024.
//

#ifndef TETROMINO_H
#define TETROMINO_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "render.h"
#include "block.h"
// #include "square_map.h"

#include <vector>
#include <iostream>
#include <tuple>

class Tetromino
{
public:

    int pos_X;
    int pos_Y;
    glm::vec2   Position, Size;
    glm::vec3   Color;
    float       Rotation;
    bool Alive;
    blockType m_blockType;
    rotationType m_rotation;



    // render state
    Texture   Sprite;
    // constructor(s)
    Tetromino();
    Tetromino(glm::vec2 pos, bool alive, rotationType rotation, glm::vec2 size, Texture sprite, int pos_x, int pos_y, blockType blocktype, glm::vec3 color = glm::vec3(1.0f));
    // draw sprite
    virtual void Draw(Render& renderer);

    virtual void changeRotation();

    virtual void changePosRight();
    virtual void changePosLeft();
    virtual void downUpdate();

    virtual bool checkAvail(movementType movType);
    virtual bool checkDownAvail(std::vector<std::vector<int>> mapValues);

    virtual std::vector< std::tuple <int, int> > getCollapseVals();
    virtual bool checkRotationAvail(std::vector<std::vector<int>> mapValues);

    virtual rotationType getNextRotation();
    virtual bool checkMovementAvail(std::vector<std::vector<int>> mapValues, movementType moveType);
    virtual void checkFinish(std::vector<std::vector<int>> mapValues, bool& endGame);
};

#endif //TETROMINO_H
