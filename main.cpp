#include <SFML/Graphics.hpp>
#include "headers/Level.h"

int main(){
    std::string file = "levels/level1.txt";
    Level level(file);
    file = "levels/level2.txt";
    Level level2(file);

    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);
/*
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(level.handle_input(window) == 1)
            break;
    }
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(level2.handle_input(window) == 1)
            break;
    }
    */

    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("img/title.jpg");
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

    sf::Sprite button_sprite;
    sf::Texture button_texture;
    button_texture.loadFromFile("img/empty_big_button.png");
    button_sprite.setTexture(button_texture);
    button_sprite.setPosition(464, 440);


    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.draw(button_sprite);
        window.display();

    }
    return 0;
}