#include <utility>

#include "../headers/Box.h"

Box::Box(const Position &position, bool status, unsigned int weight, std::string  texture_path) :
        position(position), status(status), weight(weight), texture_path(std::move(texture_path)) {
}

std::ostream& operator<<(std::ostream& os, const Box& st) {
    os << "Box (" << st.weight << "): Position: " << st.position;
    return os;
}

void Box::move(char input_){
    this -> position.update_position(input_);
    std::cout << "Cutia s-a mutat\n";
}

void Box::set_status(bool status_) {
    this -> status = status_;
}

bool Box::check_collision(const Position &position_) {
    if (Position::comparing(position_, this -> position))
    {
        std::cout << "Ai atins o cutie\n";
        return true;
    }
    return false;
}

void Box::display_box(sf::RenderWindow &window) const {
    this -> position.display_at_position(window, "img/computer.png");
}
