#include <utility>

#include "../headers/Button.h"

Button::Button(float x_axis, float y_axis, std::string text, int type, bool active):
    x_axis(x_axis), y_axis(y_axis), text(std::move(text)), type(type), active(active){

    if (type == 1){
        if (active){
            this -> texture_default = std::string ("img/buttons/button_default.png");
            this -> texture_hover = std::string ("img/buttons/button_hover.png");
        }
        else{
            this -> texture_default = std::string ("img/buttons/button_disabled.png");
            this -> texture_hover = std::string ("img/buttons/button_disabled.png");
        }
    }

    if (type == 2){
        if (active){
            this -> texture_default = std::string ("img/buttons/big_button_default.png");
            this -> texture_hover = std::string ("img/buttons/big_button_hover.png");
        }
        else{
            this -> texture_default = std::string ("img/buttons/big_button_disabled.png");
            this -> texture_hover = std::string ("img/buttons/big_button_disabled.png");
        }
    }
    
    if (type == 3){
        if (active){
            this -> texture_default = std::string ("img/buttons/square_button_default.png");
            this -> texture_hover = std::string ("img/buttons/square_button_hover.png");
        }
        else{
            this -> texture_default = std::string ("img/buttons/square_button_disabled.png");
            this -> texture_hover = std::string ("img/buttons/square_button_disabled.png");
        }
    }

    if (type == 4){
        this -> texture_default = std::string ("img/buttons/back_button.png");
        this -> texture_hover = std::string ("img/buttons/back_button_hover.png");
    }

    if (type == 5){
        this -> texture_default = std::string ("img/buttons/forward_button.png");
        this -> texture_hover = std::string ("img/buttons/forward_button_hover.png");
    }

    if (type == 6){
        this -> texture_default = std::string ("img/buttons/reset_button.png");
        this -> texture_hover = std::string ("img/buttons/reset_button_hover.png");
    }
}

void Button::display_button(sf::RenderWindow &window, bool hover) {

    sf::Vector2f position;
    position = {x_axis, y_axis};

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text display_text;
    sf::Font font;

    texture.loadFromFile(this -> texture_default);
    sprite.setPosition(position);
    font.loadFromFile("Minecraft.ttf");

    display_text.setString(text);
    if (this -> type == 1 or this -> type == 2)
        display_text.setCharacterSize(46);
    else
        display_text.setCharacterSize(80);
    display_text.setFont(font);
    display_text.setFillColor(sf::Color::White);

    sf::Vector2f center;
    if( this -> type == 1 or this -> type == 2)
        center = {position.x + (float(texture.getSize().x) - display_text.getGlobalBounds().getSize().x) / 2, position.y + float(4.5)};
    else
        center = {position.x + (float(texture.getSize().x) - display_text.getGlobalBounds().getSize().x) / 2, position.y + float(15)};


    display_text.setPosition(center);
    if (hover)
        texture.loadFromFile(this -> texture_hover);
    else
        texture.loadFromFile(this -> texture_default);
    sprite.setTexture(texture);
    window.draw(sprite);
    if(active)
        window.draw(display_text);
}


int Button::handle_button(sf::RenderWindow &window) {
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Texture texture;
    texture.loadFromFile(this -> texture_default);
    sf::Vector2u dimensiune = texture.getSize();
    bool hover = false;
    if(active){
        if (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < this -> x_axis + float(dimensiune.x) and
            float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < this -> y_axis + float(dimensiune.y)) {
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
    if(active_){
        if (button.type == 1){
            button.texture_default = std::string ("img/buttons/button_default.png");
            button.texture_hover = std::string ("img/buttons/button_hover.png");
        }

        if (button.type == 2){
            button.texture_default = std::string ("img/buttons/big_button_default.png");
            button.texture_hover = std::string ("img/buttons/big_button_hover.png");

        }

        if (button.type == 3){
            button.texture_default = std::string ("img/buttons/square_button_default.png");
            button.texture_hover = std::string ("img/buttons/square_button_hover.png");
        }
    }

    else{
        if (button.type == 1){
            button.texture_default = std::string ("img/buttons/button_disabled.png");
            button.texture_hover = std::string ("img/buttons/button_disabled.png");
        }

        if (button.type == 2){
            button.texture_default = std::string ("img/buttons/big_button_disabled.png");
            button.texture_hover = std::string ("img/buttons/big_button_disabled.png");

        }

        if (button.type == 3){
            button.texture_default = std::string ("img/buttons/square_button_disabled.png");
            button.texture_hover = std::string ("img/buttons/square_button_disabled.png");
        }
    }

}

std::ostream &operator<<(std::ostream &os, const Button &st) {
    os << "x_axis: " << st.x_axis << " y_axis: " << st.y_axis << " text: " << st.text << " type: " << st.type << " active: " << st.active;
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


