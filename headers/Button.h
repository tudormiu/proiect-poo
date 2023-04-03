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
    static void set_active(Button &buton, bool active_);
    friend std::ostream &operator<<(std::ostream &os, const Button &st);
};

class Menu{
    sf::Sprite background;
    sf::Texture background_texture;
    std::vector<Button> buttons;
    bool back_button, forward_button;

public:
    explicit Menu(std::vector<Button> buttons_, const std::string& background_path = "img/title.jpg", bool back_button = false, bool forward_button = false);
    int handle_menu(sf::RenderWindow &window);
    static int display_menu(sf::RenderWindow &window, Menu menu);
    void activate_buttons(int index);
};

#endif //OOP_BUTTON_H
