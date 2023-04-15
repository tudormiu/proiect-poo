#include <utility>

#include "../headers/Button.h"

Button::Button(float x_axis, float y_axis, const std::string& text, int type, bool active):
    x_axis(x_axis), y_axis(y_axis), type(type), active(active){


    font.loadFromFile("Minecraft.ttf");

    if (type == 1){
        this -> texture_default.loadFromFile("img/buttons/button_default.png");
        this -> texture_hover.loadFromFile("img/buttons/button_hover.png");
        this -> texture_disabled.loadFromFile("img/buttons/button_disabled.png");

        this -> text.setCharacterSize(46);

        this -> x_limit = x_axis +256;
        this -> y_limit = y_axis + 64;
    }

    if (type == 2){
        this -> texture_default.loadFromFile("img/buttons/big_button_default.png");
        this -> texture_hover.loadFromFile("img/buttons/big_button_hover.png");
        this -> texture_disabled.loadFromFile("img/buttons/big_button_disabled.png");

        this -> text.setCharacterSize(46);

        this -> x_limit = x_axis + 512;
        this -> y_limit = y_axis + 64;
    }
    
    if (type == 3){
        this -> texture_default.loadFromFile("img/buttons/square_button_default.png");
        this -> texture_hover.loadFromFile("img/buttons/square_button_hover.png");
        this -> texture_disabled.loadFromFile("img/buttons/square_button_disabled.png");

        this -> text.setCharacterSize(80);

        this -> x_limit = x_axis + 128;
        this -> y_limit = y_axis + 128;
    }

    if (type == 4){
        this -> texture_default.loadFromFile("img/buttons/back_button.png");
        this -> texture_hover.loadFromFile("img/buttons/back_button_hover.png");
        this -> texture_disabled.loadFromFile("img/buttons/small_square_button_disabled.png");

        this -> x_limit = x_axis + 64;
        this -> y_limit = y_axis + 64;
    }

    if (type == 5){
        this -> texture_default.loadFromFile("img/buttons/forward_button.png");
        this -> texture_hover.loadFromFile("img/buttons/forward_button_hover.png");
        this -> texture_disabled.loadFromFile("img/buttons/small_square_button_disabled.png");

        this -> x_limit = x_axis + 64;
        this -> y_limit = y_axis + 64;
    }

    if (type == 6){
        this -> texture_default.loadFromFile("img/buttons/reset_button_default.png");
        this -> texture_hover.loadFromFile("img/buttons/reset_button_hover.png");
        this -> texture_disabled.loadFromFile("img/buttons/small_square_button_disabled.png");

        this -> x_limit = x_axis + 64;
        this -> y_limit = y_axis + 64;
    }

    button_default.setTexture(texture_default);
    button_hover.setTexture(texture_hover);
    button_disabled.setTexture(texture_disabled);

    button_default.setPosition(x_axis, y_axis);
    button_hover.setPosition(x_axis, y_axis);
    button_disabled.setPosition(x_axis, y_axis);

    this -> text.setString(text);
    this -> text.setFont(font);
    this -> text.setFillColor(sf::Color::White);

    sf::Vector2f center;
    if( this -> type == 1 or this -> type == 2)
        center = {x_axis + (float(this -> texture_default.getSize().x) - this -> text.getGlobalBounds().getSize().x) / 2, y_axis + float(4.5)};
    else
        center = {x_axis + (float(this -> texture_default.getSize().x) - this -> text.getGlobalBounds().getSize().x) / 2, y_axis + float(15)};

    this -> text.setPosition(center);

    this -> text.setFont(font);

}

void Button::display_button(sf::RenderWindow &window, bool hover) {

    if (active){
        if(hover)
            window.draw(button_hover);
        else
            window.draw(button_default);

        window.draw(text);
    }
    else
        window.draw(button_disabled);
}


int Button::handle_button(sf::RenderWindow &window) {
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    bool hover = false;
    if(active){
        if (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < this -> x_limit and
            float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < this -> y_limit) {
            hover = true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
                return 1;
            }
        }
    }
    display_button(window, hover);

    return 0;
}

void Button::set_active(Button &button, bool active_) {
    button.active = active_;
}

std::ostream &operator<<(std::ostream &os, const Button &st) {
    os << "x_axis: " << st.x_axis << " y_axis: " << st.y_axis << " type: " << st.type << " active: " << st.active;
    return os;
}

Menu::Menu(std::vector<Button> buttons, const std::string& background_path, bool back_button, bool forward_button) :
    buttons(std::move(buttons)), back_button(back_button), forward_button(forward_button) {
    this -> background_texture.loadFromFile(background_path);
    this -> background.setTexture(background_texture);

    this -> background.setTexture(this -> background_texture);
    this -> background.setPosition(0, 0);
}

int Menu::handle_menu(sf::RenderWindow &window) {
    window.clear();
    window.draw(this -> background);
    for (int i = 0; i < int(this -> buttons.size()); i++)
        if(this -> buttons[i].handle_button(window) == 1)
            return i + 1;
    if(this -> back_button)
    {
        Button back_button_(120, 492, "", 4);
        if(back_button_.handle_button(window) == 1)
            return -1;
    }
    if(this -> forward_button)
    {
        Button forward_button_(1256, 492, "", 5);
        if(forward_button_.handle_button(window) == 1)
            return -2;
    }

    window.display();
    return 0;
}

int Menu::display_menu(sf::RenderWindow &window, Menu menu) {
    while (window.isOpen()) {
        window.clear();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int selected_level = menu.handle_menu(window);
        if(selected_level)
            return selected_level;
    }
    return 0;
}

void Menu::activate_buttons(int index) {
    for (int i = 0; i <= index; i++)
        Button::set_active(buttons[i], true);
    for (int i = index + 1; i < int(buttons.size()); i++)
        Button::set_active(buttons[i], false);
}


