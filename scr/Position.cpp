#include "../headers/Position.h"

Position::Position(int xAxis, int yAxis) : x_axis(xAxis), y_axis(yAxis) {
    //std::cout << "Constructor initializare poz\n";
}
Position::Position(const Position& other) : x_axis{other.x_axis}, y_axis{other.y_axis} {
    //std::cout << "Constructor copiere poz\n";
}

Position& Position::operator=(const Position& other) {
    x_axis = other.x_axis;
    y_axis = other.y_axis;
    //std::cout << "operator= copiere poz\n";
    return *this;
}

Position::~Position() {
    //std::cout << "Destr poz\n";
}


bool Position::comparing(Position const& position1_, Position  const& position2_){
    return position1_.x_axis == position2_.x_axis && position1_.y_axis == position2_.y_axis;
}

[[nodiscard]] bool Position::position_outside_limits(const int down_, const int right_) const{
    if (this -> x_axis >= 0 && this -> x_axis < down_ && this -> y_axis >= 0 && this -> y_axis < right_)
        return false;
    std::cout << "Ai atins limita tablei\n";
    return true;
}

void Position::update_position(const char input_) {
    this -> x_axis = this -> x_axis + (input_ == 'd' ? 1 : (input_ == 'a' ? -1 : 0));
    this -> y_axis = this -> y_axis + (input_ == 'w' ? 1 : (input_ == 's' ? -1 : 0));
}

std::ostream &operator<<(std::ostream &os, const Position &st){
    os << "x_axis: " << st.x_axis << ", y_axis: " << st.y_axis << "\n";
    return os;
}

