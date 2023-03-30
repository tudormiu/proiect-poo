#include <utility>

#include "../headers/Button.h"

Button::Button(const sf::Vector2f &position, std::string text, int type, bool active):
            position(position), text(std::move(text)), active(active) {

    if (type == 1){
        if (active){
            this -> texture_default.loadFromFile("img/buttons/button_default.png");
            this -> texture_hover.loadFromFile("img/buttons/button_hover.png");
        }
        else{
            this -> texture_default.loadFromFile("img/buttons/button_disabled.png");
            this -> texture_hover.loadFromFile("img/buttons/button_disabled.png");
        }


    }

    if (type == 2){
        if (active){
            this -> texture_default.loadFromFile("img/buttons/big_button_default.png");
            this -> texture_hover.loadFromFile("img/buttons/big_button_hover.png");
        }
        else{
            this -> texture_default.loadFromFile("img/buttons/big_button_disabled.png");
            this -> texture_hover.loadFromFile("img/buttons/big_button_disabled.png");
        }

    }

    this -> sprite_default.setTexture(texture_default);
    this -> sprite_default.setPosition(position);

    this -> sprite_hover.setTexture(texture_hover);
    this -> sprite_hover.setPosition(position);
}

void Button::display_button(sf::RenderWindow &window, bool hover) {

    sf::Text display_text;
    display_text.setString(text);
    display_text.setCharacterSize(46);
    sf::Font font;
    font.loadFromFile("minecraft.ttf");
    display_text.setFont(font);
    display_text.setFillColor(sf::Color::White);

    sf::Vector2f center;
    center = {position.x + (float(this -> texture_default.getSize().x) - display_text.getGlobalBounds().getSize().x) / 2, position.y + float(4.5)};

    display_text.setPosition(center);
    if (hover)
        window.draw(this -> sprite_hover);

    else
        window.draw(this -> sprite_default);
    if(active)
        window.draw(display_text);
}


int Button::handle_button(sf::RenderWindow &window) {
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2u dimensiune = this -> texture_default.getSize();
    if (float(mouse_position.x) > this -> position.x && float(mouse_position.x) < this -> position.x + float(dimensiune.x) and
        float(mouse_position.y) > this -> position.y && float(mouse_position.y) < this -> position.y + float(dimensiune.y)) {
        display_button(window, true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
            return 1 ;
        }
    }
    else
        display_button(window);
    return 0;
}

/*
void Button::set_active(bool active_) {
    this -> active = active_;
}
*/

Menu::Menu(std::vector<Button> buttons, const std::string& background_path) : buttons(std::move(buttons)) {
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
    window.display();
    return 0;
}

