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
    font.loadFromFile("minecraft.ttf");

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
    if (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < this -> x_axis + float(dimensiune.x) and
        float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < this -> y_axis + float(dimensiune.y)) {
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

int Menu::display_menu(sf::RenderWindow &window, Menu menu) {
    int selected_level;
    while (window.isOpen()) {
        window.clear();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        selected_level = menu.handle_menu(window);
        if(selected_level)
            return selected_level;
    }
    return 0;
}


