#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    float x_axis, y_axis;
    std::string text;

    int type;
    bool active;

    std::string texture_default;
    std::string texture_hover;

public:
    explicit Button(float x_axis, float y_axis, std::string text, int type = 1, bool active = true);
    void display_button(sf::RenderWindow &window, bool hover = false);
    int handle_button(sf::RenderWindow &window);
    //void set_active(bool active_);
};

class Menu{
    sf::Sprite background;
    sf::Texture background_texture;
    std::vector<Button> buttons;

public:
    explicit Menu(std::vector<Button> buttons_, const std::string& background_path = "img/title.jpg");
    int handle_menu(sf::RenderWindow &window);
};

#endif //OOP_BUTTON_H
