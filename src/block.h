//
// Created by trangnt on 18/11/2024.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <tuple>
#include <vector>

enum blockType {
    L,
    S,
    I,
    Z,
    J,
    O,
    T
};

enum movementType {
    Left_movement,
    Right_movement
};


enum rotationType {
    Up_rotation,
    Down_rotation,
    Left_rotation,
    Right_rotation
};

class Block
{
public:
    std::vector< std::tuple <int, int> > created_sequence;
    Block(blockType blockname, rotationType rotation);
    std::vector<std::tuple <int, int> > getSequence();
    std::pair<int, std::string> getName(blockType type);
};

#endif //BLOCK_H
