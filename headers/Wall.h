#ifndef OOP_WALL_H
#define OOP_WALL_H
#include <iostream>
#include "Position.h"

class Wall{
    Position position;

public:
    explicit Wall(const Position &position);

    friend std::ostream &operator<<(std::ostream &os, const Wall &st);

    bool check_collision(Position const& position_);

};


#endif //OOP_WALL_H
