#ifndef OOP_POSITION_H
#define OOP_POSITION_H
#include <iostream>
#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

class Position{
    int x_axis, y_axis;

public:
    Position(int xAxis, int yAxis);
    Position(const Position& other);
    Position& operator=(const Position& other);
    ~Position();
    static bool comparing(Position const& position1_, Position  const& position2_);
    [[nodiscard]] bool position_outside_limits(int down_, int right_) const;
    void update_position(char input_);
    friend std::ostream &operator<<(std::ostream& os, const Position& st);
    void display_at_position(sf::RenderWindow &window, const std::string& texture_path) const;
};

#endif //OOP_POSITION_H