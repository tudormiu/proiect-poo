#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include "Position.h"
#include <SFML/Graphics.hpp>

class Player{
    Position<int> position;
    int orientation;
    unsigned power;
    std::string texture_path;

public:
    explicit Player(const Position<int> &position, int orientation = 0, unsigned power = 1, std::string  texture_path = "img/bulb_jos.png");
    Player(Player const& other);
    Player();
    Player& operator=(Player const& other);
    friend std::ostream& operator<<(std::ostream& os, const Player& st);
    [[nodiscard]] Position<int> &getPosition();
    void move(char input_);
    void power_up(int amount = 1);
    void display_player(sf::RenderWindow &window, float offset_x, float offset_y) const;

};

#endif //OOP_PLAYER_H
