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
    static int add_extra_button(sf::RenderWindow &window, Button *, bool active);
    int add_buttons(sf::RenderWindow &window);
    int display_menu(sf::RenderWindow &window);
    void activate_buttons(int index);
};

class Level_menu : public Menu{
    bool back_button_status, forward_button_status;
    Button *back_button, *forward_button;

public:
    explicit Level_menu(std::vector<Button> buttons_, const std::string& background_path = "img/title.jpg",
                        bool back_button_status = true, bool forward_button_status = false,
                        Button *back_button = nullptr, Button *forward_button = nullptr);
    int handle_menu(sf::RenderWindow &window) override;
};



#endif //OOP_MENU_H
