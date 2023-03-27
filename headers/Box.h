#ifndef OOP_BOX_H
#define OOP_BOX_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Box {
    Position position;
    bool status;
    unsigned weight;
    std::string texture_path;

public:
    explicit Box(const Position &position, bool status = false, unsigned weight = 1, std::string  texture_path = "img/computer.png");
    friend std::ostream& operator<<(std::ostream& os, const Box& st);
    void move(char input_);
    void set_status(bool status_);
    bool check_collision(Position const& position_);
    void display_box(sf::RenderWindow &window) const;
};


#endif //OOP_BOX_H
