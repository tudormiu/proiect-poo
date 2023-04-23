#ifndef OOP_POSITION_H
#define OOP_POSITION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Exceptions.h"

class Position{
    int x_axis, y_axis;

public:
    explicit Position(int xAxis = -1, int yAxis = -1);
    Position(const Position& other);
    Position& operator=(const Position& other);
    ~Position();
    static bool comparing(Position const& position1_, Position  const& position2_);
    [[nodiscard]] bool position_outside_limits(int down_, int right_) const;
    void update_position(char input_);
    friend std::ostream &operator<<(std::ostream& os, const Position& st);
    void display_at_position(sf::RenderWindow &window, const std::string& texture_path, float offset_x = 0,
                             float offset_y = 0, float scale = 0.76, float scale_x = 1, float scale_y = 1) const;
    void display_at_position(sf::RenderWindow &window, sf::Sprite& sprite, float offset_x = 0, float offset_y = 0,
                             float scale = 0.76, float scale_x = 1, float scale_y = 1) const;
};

#endif //OOP_POSITION_H
