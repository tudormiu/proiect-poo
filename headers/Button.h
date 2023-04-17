#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    float x_axis, y_axis, x_limit, y_limit;

    int type;
    bool active;

    sf::Texture texture_default, texture_hover, texture_disabled;
    sf::Sprite button_default, button_hover, button_disabled;
    sf::Font font;
    sf::Text text;

public:
    explicit Button(float x_axis, float y_axis, const std::string& text, int type = 1, bool active = true);
    void display_button(sf::RenderWindow &window, bool hover = false);
    int handle_button(sf::RenderWindow &window);
    static void set_active(Button &buton, bool active_);
    friend std::ostream &operator<<(std::ostream &os, const Button &st);
};

#endif //OOP_BUTTON_H
