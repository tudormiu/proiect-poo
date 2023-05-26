#include <utility>
#include "../headers/Wall.h"

Wall::Wall(const Position<int> &position, std::string  texture_path) : position(position), texture_path(std::move(texture_path)) {}

std::ostream& operator<<(std::ostream& os, const Wall& st) {
    os << "Wall: " << st.position;
    return os;
}

bool Wall::check_collision(const Position<int> &position_) {
    Position<int> currentPosition = this->position;
    if (currentPosition.comparing(position_, currentPosition))
    {
        return true;
    }
    return false;
}


void Wall::display_wall(sf::RenderWindow &window, float offset_x, float offset_y) const {
    this -> position.display_at_position(window, "img/wall.png", offset_x, offset_y);
}
