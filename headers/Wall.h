#ifndef OOP_WALL_H
#define OOP_WALL_H
#include <iostream>
#include "Position.h"
#include <SFML/Graphics.hpp>

class Wall{
    Position<int> position;
    std::string texture_path;

public:
    explicit Wall(const Position<int> &position, std::string  texture_path = "img/wall.png");
    friend std::ostream &operator<<(std::ostream &os, const Wall &st);
    bool check_collision(Position<int> const& position_);
    void display_wall(sf::RenderWindow &window, float offset_x, float offset_y) const;
};


#endif //OOP_WALL_H
