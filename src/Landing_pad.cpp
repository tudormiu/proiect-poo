#include "../headers/Landing_pad.h"

Landing_pad::Landing_pad(const Position<int> &position, std::string texture_path, bool active):
                position(position), texture_path(std::move(texture_path)), active(active) {}

std::ostream &operator<<(std::ostream &os, const Landing_pad &st) {
    os << "Landing pad: " << st.position<< " Is active: " << st.active;
    return os;
}

void Landing_pad::display_landing_pad(sf::RenderWindow &window, float offset_x, float offset_y) const {
    this -> position.display_at_position(window, "img/landing_pad.png", offset_x, offset_y);
}

bool Landing_pad::is_active() const {
    return this -> active;
}

bool Landing_pad::check_collision(const Position<int> &position_) {
    Position<int> currentPosition = this->position;
    if (currentPosition.comparing(position_, currentPosition))
    {
        return true;
    }
    return false;
}


