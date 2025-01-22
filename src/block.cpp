//
// Created by trangnt on 18/11/2024.
//

#include "block.h"

Block::Block(blockType blockname, rotationType rotation) {
    if (blockname == L) {
        if (rotation == Up_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, 1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Right_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, -1);
            std::tuple<int, int> order4 = std::tuple< int, int >(2, -1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Down_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order2 = std::tuple< int, int >(1, -1);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, 1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Left_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(1, -1);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(-1, 0);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
    }
    else if (blockname == O) {
        std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
        std::tuple<int, int> order2 = std::tuple< int, int >(0, -1);
        std::tuple<int, int> order3 = std::tuple< int, int >(1, 0);
        std::tuple<int, int> order4 = std::tuple< int, int >(1, -1);
        this->created_sequence.push_back(order1);
        this->created_sequence.push_back(order2);
        this->created_sequence.push_back(order3);
        this->created_sequence.push_back(order4);
    }
    else if (blockname == I) {
        if (rotation == Up_rotation || rotation == Down_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order4 = std::tuple< int, int >(0, -2);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Left_rotation || rotation == Right_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(-1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(-2, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, 0);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
    }
    else if (blockname == J) {
        if (rotation == Up_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order4 = std::tuple< int, int >(-1, 1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Right_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, 1);
            std::tuple<int, int> order4 = std::tuple< int, int >(2, 1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Down_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order4 = std::tuple< int, int >(0, 2);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Left_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(-1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, 1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
    }
    else if (blockname == Z) {
        if (rotation == Up_rotation || rotation == Down_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order4 = std::tuple< int, int >(-1, -1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Right_rotation || rotation == Left_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, -1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
    }
    else if (blockname == S) {
        if (rotation == Up_rotation || rotation == Down_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(-1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, -1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Right_rotation || rotation == Left_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order3 = std::tuple< int, int >(-1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(-1, -1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
    }
    else if (blockname == T) {
        if (rotation == Up_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(-1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(0, -1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Right_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order4 = std::tuple< int, int >(1, 0);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Down_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(1, 0);
            std::tuple<int, int> order3 = std::tuple< int, int >(-1, 0);
            std::tuple<int, int> order4 = std::tuple< int, int >(0, 1);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
        else if (rotation == Left_rotation) {
            std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
            std::tuple<int, int> order2 = std::tuple< int, int >(0, 1);
            std::tuple<int, int> order3 = std::tuple< int, int >(0, -1);
            std::tuple<int, int> order4 = std::tuple< int, int >(-1, 0);
            this->created_sequence.push_back(order1);
            this->created_sequence.push_back(order2);
            this->created_sequence.push_back(order3);
            this->created_sequence.push_back(order4);
        }
    }
    else {
        std::tuple<int, int> order1 = std::tuple< int, int >(0, 0);
        std::tuple<int, int> order2 = std::tuple< int, int >(0, 0);
        std::tuple<int, int> order3 = std::tuple< int, int >(0, 0);
        std::tuple<int, int> order4 = std::tuple< int, int >(0, 0);
        this->created_sequence.push_back(order1);
        this->created_sequence.push_back(order2);
        this->created_sequence.push_back(order3);
        this->created_sequence.push_back(order4);
    }
}

std::vector<std::tuple <int, int> > Block::getSequence() {
    return this->created_sequence;
}

std::pair<int, std::string> Block::getName(blockType type) {
    switch (type) {
        case I: return {1, "I"}; break;
        case J: return {2, "J"}; break;
        case L: return {3, "L"}; break;
        case O: return {4, "O"}; break;
        case S: return {5, "S"}; break;
        case T: return {6, "T"}; break;
        case Z: return {7, "Z"}; break;
    }
}
