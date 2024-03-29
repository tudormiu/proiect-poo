#include <utility>
#include "../headers/Box.h"

Box::Box(const Position<int> &position, bool status, unsigned int weight, std::string  texture_path) :
        position(position), status(status), weight(weight), texture_path(std::move(texture_path)) {
}

std::ostream& operator<<(std::ostream& os, const Box& st) {
    os << "Box (" << st.weight << "): Position: " << st.position;
    return os;
}

void Box::move(char input_, std::vector<Landing_pad> &landing_pads){
    this -> position.update_position(input_);
    for (Landing_pad &landing_pad: landing_pads)
        if (landing_pad.check_collision(this -> position))
        {
            this -> set_status(true);
            return;
        }
    this -> set_status(false);

    std::cout << "Cutia s-a mutat\n";
}

void Box::set_status(bool status_) {
    this -> status = status_;
}

bool Box::get_status() const {
    return status;
}

bool Box::check_collision(const Position<int> &position_) {
    Position<int> currentPosition = this->position;
    if (currentPosition.comparing(position_, currentPosition))
    {
        return true;
    }
    return false;
}

void Box::display_box(sf::RenderWindow &window, float offset_x, float offset_y) const {
    if(this -> status)
        this -> position.display_at_position(window, "img/computer_on.png", offset_x, offset_y);
    else
        this -> position.display_at_position(window, "img/computer.png", offset_x, offset_y);
}

