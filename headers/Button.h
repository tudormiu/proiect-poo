#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    sf::Vector2f position;
    std::string texture_path;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    explicit Button(const sf::Vector2f &position, const std::string &texture_path);
    void display_button(sf::RenderWindow &window, const float &scale = 1);
    int handle_button(sf::RenderWindow &window);
};


#endif //OOP_BUTTON_H
