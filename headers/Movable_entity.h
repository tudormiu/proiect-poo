#ifndef OOP_MOVABLE_ENTITY_H
#define OOP_MOVABLE_ENTITY_H

#include "Position.h"
#include "Landing_pad.h"
#include <SFML/Graphics.hpp>


class Movable_entity {
    Position position;
    sf::Sprite sprite_default, sprite_active;
    sf::Texture texture_default, texture_active;
    bool status;

public:
    explicit Movable_entity(const Position &position, const std::string&  texture_path_default, const std::string&  texture_path_active, bool status = "false");
    friend std::ostream &operator<<(std::ostream &os, const Movable_entity &st);
    void move(char input_, std::vector<Landing_pad> &landing_pads);
    void set_status(bool status_);
    [[nodiscard]] bool get_status() const;
    bool check_collision(Position const& position_);
    void display_movable_entity(sf::RenderWindow &window, float offset_x, float offset_y);
};

#endif //OOP_MOVABLE_ENTITY_H
