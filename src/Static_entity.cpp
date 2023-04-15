#include "../headers/Static_entity.h"

Static_entity::Static_entity(const Position &position, const std::string&  texture_path) : position(position){
    if (!texture.loadFromFile(texture_path))
    {
        std::cout << "Error loading texture\n";
    }
    sprite.setTexture(texture);
}

std::ostream& operator<<(std::ostream& os, const Static_entity& st) {
    os << "Static_entity: " << st.position;
    return os;
}

bool Static_entity::check_collision(Position const& position_){
    if (Position::comparing(position_, this -> position))
    {
        std::cout << "Ai lovit o entitate statica\n";
        return true;
    }
    return false;
}

void Static_entity::display_static_entity(sf::RenderWindow &window, float offset_x, float offset_y) {
    this -> position.display_at_position(window, this -> sprite, offset_x, offset_y);
}

Target::Target(const Position &position, const std::string&  texture_path, bool active) :
    Static_entity(position, texture_path), active(active) {}

bool Target::is_active() const {
    return this -> active;
}