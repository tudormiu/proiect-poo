#ifndef OOP_BOARD_H
#define OOP_BOARD_H

#include <iostream>
#include <vector>
#include "Wall.h"
#include "Player.h"
#include "Box.h"

class Board {
    int lines, columns;
    std::vector<Wall> walls;
    std::vector<Box> boxes;
    Player player;

public:
    Board(int lines, int columns, const std::vector<Wall> &walls, const std::vector<Box> &boxes, Player player);
    friend std::ostream &operator<<(std::ostream &os, const Board &st);
    void move_player(char input_);
    bool box_collisions(char input_);
    void display_empty_board(sf::RenderWindow &window) const;
    void display_board(sf::RenderWindow &window) const;
};


#endif //OOP_BOARD_H
