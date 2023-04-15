#ifndef OOP_STATIC_ENTITY_H
#define OOP_STATIC_ENTITY_H
#include <iostream>
#include "Position.h"
#include <SFML/Graphics.hpp>


class Static_entity {
Position position;
sf::Sprite sprite;
sf::Texture texture;

public:
    explicit Static_entity(const Position &position, const std::string&  texture_path);
    friend std::ostream &operator<<(std::ostream &os, const Static_entity &st);
    bool check_collision(Position const& position_);
    void display_static_entity(sf::RenderWindow &window, float offset_x, float offset_y);
};

class Target : public Static_entity {
    bool active;

public:
    explicit Target(const Position &position, const std::string&  texture_path = "img/landing_pad.png", bool active = true);
    [[nodiscard]] bool is_active() const;
};

#endif //OOP_STATIC_ENTITY_H
