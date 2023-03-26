#include "../headers/Box.h"

Box::Box(const Position &position, bool status, unsigned int weight) : position(position), status(status), weight(weight){
    //std::cout << "Constructor initializare cutie\n";
}

std::ostream& operator<<(std::ostream& os, const Box& st) {
    os << "Box (" << st.weight << ") position: " << st.position << "\n";
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
