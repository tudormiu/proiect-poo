#include "../headers/Movable_entity.h"

Movable_entity::Movable_entity(const Position &position, const std::string&  texture_path_default, const std::string&  texture_path_active, bool status) :
        position(position), status(status) {
    if (!texture_default.loadFromFile(texture_path_default))
    {
        std::cout << "Error loading texture\n";
    }
    sprite_default.setTexture(texture_default);

    if (!texture_active.loadFromFile(texture_path_active))
    {
        std::cout << "Error loading texture\n";
    }
    sprite_active.setTexture(texture_active);
}

std::ostream &operator<<(std::ostream &os, const Movable_entity &st) {
    os << "Movable_entity: " << st.position;
    return os;
}

void Movable_entity::move(char input_, std::vector<Landing_pad> &landing_pads){
    this -> position.update_position(input_);
    for (Landing_pad &landing_pad: landing_pads)
        if (landing_pad.check_collision(this -> position))
        {
            this -> set_status(true);
            return;
        }
    this -> set_status(false);

    std::cout << "Entitatea s-a mutat\n";
}

void Movable_entity::set_status(bool status_) {
    this -> status = status_;
}

bool Movable_entity::get_status() const {
    return status;
}

bool Movable_entity::check_collision(const Position &position_) {
    if (Position::comparing(position_, this -> position))
    {
        std::cout << "Ai atins o entitate\n";
        return true;
    }
    return false;
}

void Movable_entity::display_movable_entity(sf::RenderWindow &window, float offset_x, float offset_y) {
    if(this -> status)
        this -> position.display_at_position(window, this -> sprite_active, offset_x, offset_y);
    else
        this -> position.display_at_position(window, this -> sprite_default, offset_x, offset_y);
}
