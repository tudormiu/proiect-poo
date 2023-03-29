#include "../headers/Button.h"

Button::Button(const sf::Vector2f &position, const std::string &texture_path) : position(position),
                                                                                texture_path(texture_path) {
    this -> texture.loadFromFile(texture_path);
    this -> sprite.setTexture(texture);
}

void Button::display_button(sf::RenderWindow &window, const float &scale) {
    this -> sprite.setScale(scale, scale);
    this -> sprite.setPosition(position);
    window.draw(sprite);
}

int Button::handle_button(sf::RenderWindow &window) {
    this -> display_button(window);
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2u dimensiune = this -> texture.getSize();
    if (float(mouse_position.x) > this -> position.x && float(mouse_position.x) < this -> position.x + float(dimensiune.x) and
        float(mouse_position.y) > this -> position.y && float(mouse_position.y) < this -> position.y + float(dimensiune.y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //std::cout << "apasat\n";
            }
            return 1 ;
        }
    }
    return 0;
}
