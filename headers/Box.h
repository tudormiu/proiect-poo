#ifndef OOP_BOX_H
#define OOP_BOX_H
#include "Position.h"


class Box {
    Position position;
    bool status;
    unsigned weight;
public:
    explicit Box(const Position &position, bool status = false, unsigned weight = 1);
    friend std::ostream& operator<<(std::ostream& os, const Box& st);
    void move(char input_);
    void set_status(bool status_);
    bool check_collision(Position const& position_);
};


#endif //OOP_BOX_H
