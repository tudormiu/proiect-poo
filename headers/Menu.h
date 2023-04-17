#ifndef OOP_MENU_H
#define OOP_MENU_H
#include "Position.h"
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu{
    sf::Sprite background;
    sf::Texture background_texture;
    std::vector<Button> buttons;

public:
    explicit Menu(std::vector<Button> buttons_, const std::string& background_path = "img/title.jpg");
    virtual int handle_menu(sf::RenderWindow &window);

    static void add_background(Menu *this_, sf::RenderWindow &window);
    int add_buttons(sf::RenderWindow &window);
    static int add_back_button(sf::RenderWindow &window, bool active);
    static int add_forward_button(sf::RenderWindow &window, bool active);

    int display_menu(sf::RenderWindow &window);
    void activate_buttons(int index);
};

class Level_menu : public Menu{
    bool back_button, forward_button;

public:
    explicit Level_menu(std::vector<Button> buttons_, const std::string& background_path = "img/title.jpg", bool back_button = true, bool forward_button = false);
    int handle_menu(sf::RenderWindow &window) override;
};



#endif //OOP_MENU_H
