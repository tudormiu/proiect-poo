#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    sf::Vector2f position;
    std::string text;

    bool active;

    sf::Texture texture_default;
    sf::Sprite sprite_default;

    sf::Texture texture_hover;
    sf::Sprite sprite_hover;

public:
    explicit Button(const sf::Vector2f &position, std::string text, int type = 1, bool active = true);
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
