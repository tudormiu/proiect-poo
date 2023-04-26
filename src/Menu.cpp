#include "../headers/Menu.h"


Menu::Menu(std::vector<Button*> buttons, const std::string& background_path) :
        buttons(std::move(buttons)) {
    if(!this -> background_texture.loadFromFile(background_path))
        throw eroare_imagine(background_path);
    this -> background.setTexture(background_texture);

    this -> background.setTexture(this -> background_texture);
    this -> background.setPosition(0, 0);
}

int Menu::handle_menu(sf::RenderWindow &window) {
    window.clear();
    add_background(this, window);
    int button_pressed = add_buttons(window);
    if(button_pressed != 0)
        return button_pressed;
    window.display();
    return 0;
}

void Menu::add_background(Menu *this_, sf::RenderWindow &window){
    window.draw(this_ -> background);
}

int Menu::add_extra_button(sf::RenderWindow &window, Button *button, bool active) {
    Button::set_active(button,active);
    if(button -> handle_button(window) == 1)
        return 1;
    return 0;
}

int Menu::add_buttons(sf::RenderWindow &window) {
    for (int i = 0; i < int(this -> buttons.size()); i++)
        if(this -> buttons[i] -> handle_button(window) == 1)
            return i + 1;
    return 0;
}

int Menu::display_menu(sf::RenderWindow &window) {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int selected_level = handle_menu(window);
        if(selected_level)
            return selected_level;
    }
    return 0;
}

void Menu::activate_buttons(int index) {
    for (int i = 0; i < index; i++)
        Button::set_active(buttons[i], true);
    for (int i = index + 1; i < int(buttons.size()); i++)
        Button::set_active(buttons[i], false);
}

Level_menu::Level_menu(std::vector<Button *> buttons, const std::string& background_path, bool back_button_status,
                       bool forward_button_status, Button *back_button, Button *forward_button) :
        Menu(std::move(buttons), background_path), back_button_status(back_button_status),
        forward_button_status(forward_button_status), back_button(back_button), forward_button(forward_button) {
}

int Level_menu::handle_menu(sf::RenderWindow &window) {
    window.clear();
    add_background(this, window);
    int button_pressed = add_buttons(window);
    if(button_pressed != 0)
        return button_pressed;

    if(add_extra_button(window, back_button, back_button_status) == 1)
            return -1;

    if(add_extra_button(window, forward_button, forward_button_status) == 1)
            return -2;

    window.display();
    return 0;
}