#include "../headers/Landing_pad.h"

Landing_pad::Landing_pad(const Position &position, std::string texture_path, bool active):
                position(position), texture_path(std::move(texture_path)), active(active) {}

std::ostream &operator<<(std::ostream &os, const Landing_pad &st) {
    os << "Landing pad: " << st.position<< " Is active: " << st.active;
    return os;
}

void Landing_pad::display_landing_pad(sf::RenderWindow &window) const {
    this -> position.display_at_position(window, "img/landing_pad.png");
}

bool Landing_pad::is_active() const {
    return this -> active;
}

bool Landing_pad::check_collision(const Position &position_) {
    if (Position::comparing(position_, this -> position))
    {
        std::cout << "Cutia este pe o platforma\n";
        return true;
    }
    return false;
}

