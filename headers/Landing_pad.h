#ifndef OOP_LANDING_PAD_H
#define OOP_LANDING_PAD_H
#include "Position.h"


class Landing_pad {
    Position position;
    std::string texture_path;
    bool active;

public:
    explicit Landing_pad(const Position &position, std::string  texture_path = "img/landing_pad.png", bool active = true);
    friend std::ostream &operator<<(std::ostream &os, const Landing_pad &st);
    void display_landing_pad(sf::RenderWindow &window, float offset_x, float offset_y) const;
    [[nodiscard]] bool is_active() const;
    bool check_collision(Position const& position_);
};


#endif //OOP_LANDING_PAD_H
