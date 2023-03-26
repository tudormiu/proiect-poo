#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include "Position.h"

class Player{
    Position position;
    int orientation;
    unsigned power;

public:
    explicit Player(const Position &position, int orientation = 1, unsigned power = 1);
    friend std::ostream& operator<<(std::ostream& os, const Player& st);
    [[nodiscard]] Position &getPosition();
    void move(char input_);
    void power_up(int amount = 1);

};

#endif //OOP_PLAYER_H
