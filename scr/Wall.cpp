#include "../headers/Wall.h"

Wall::Wall(const Position &position) : position(position) {
    //std::cout << "Constructor initializare zid\n";
}

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