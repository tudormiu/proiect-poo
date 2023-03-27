#include <utility>

#include "../headers/Wall.h"

Wall::Wall(const Position &position, std::string  texture_path) : position(position), texture_path(std::move(texture_path)) {}

std::ostream& operator<<(std::ostream& os, const Wall& st) {
    os << "Wall: " << st.position;
    return os;
}

bool Wall::check_collision(Position const& position_){
    if (Position::comparing(position_, this -> position))
    {
        std::cout << "Ai lovit un zid\n";
        return true;
    }
    return false;
}

void Wall::display_wall(sf::RenderWindow &window) const {
    this -> position.display_at_position(window, "img/wall.png");
}
