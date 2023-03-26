#include "../headers/Player.h"

 Player::Player(const Position &position, int orientation, unsigned power) : position(position), orientation(orientation),
                                                                power(power){
    //std::cout << "Constructor initializare juc\n";
}

std::ostream& operator<<(std::ostream& os, const Player& st) {
    os << "Position: " << st.position << "\n";
    return os;
}

Position &Player::getPosition() {
    return position;
}

void Player::move(char input_){
    this -> position.update_position(input_);
    if (input_ == 's')
        this -> orientation = 1;
    else if (input_ == 'w')
        this -> orientation = 2;
    else if (input_ == 'a')
        this -> orientation = 3;
    else if (input_ == 'd')
        this -> orientation = 4;
}

void Player::power_up(int amount) {
    this -> power+= amount;
}

