#ifndef OOP_BOX_H
#define OOP_BOX_H
#include "Position.h"
#include "Landing_pad.h"
#include <SFML/Graphics.hpp>


class Box {
    Position position;
    bool status;
    unsigned weight;
    std::string texture_path;

public:
    explicit Box(const Position &position, bool status = false, unsigned weight = 1, std::string  texture_path = "img/computer.png");
    friend std::ostream& operator<<(std::ostream& os, const Box& st);
    void move(char input_, std::vector<Landing_pad> &landing_pads);
    void set_status(bool status_);
    [[nodiscard]] bool get_status() const;
    bool check_collision(Position const& position_);
    void display_box(sf::RenderWindow &window, float offset_x, float offset_y) const;
};


#endif //OOP_BOX_H
