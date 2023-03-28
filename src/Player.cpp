#include <utility>
#include "../headers/Player.h"

Player::Player(const Position &position, int orientation, unsigned power, std::string  texture_path) :
            position(position), orientation(orientation), power(power), texture_path(std::move(texture_path)){}

Player &Player::operator=(const Player &other)= default;

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

void Player::display_player(sf::RenderWindow &window) const {
    if (this -> orientation == 1)
        this -> position.display_at_position(window, "img/bulb_jos.png");
    else if (this -> orientation == 2)
        this -> position.display_at_position(window, "img/bulb_sus.png");
    else if (this -> orientation == 3)
        this -> position.display_at_position(window, "img/bulb_stanga.png");
    else if (this -> orientation == 4)
        this -> position.display_at_position(window, "img/bulb_dreapta.png");
    else
        this -> position.display_at_position(window, "img/bulb_off.png");
}

Player::Player(const Player &other) {
    this -> position = other.position;
    this -> orientation = other.orientation;
    this -> power = other.power;
    this -> texture_path = other.texture_path;

}

Player::Player() {
    this -> position = Position(0, 0);
    this -> orientation = 0;
    this -> power = 1;
    this -> texture_path = "img/bulb_jos.png";

}
