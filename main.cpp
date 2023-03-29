#include <SFML/Graphics.hpp>
#include "headers/Level.h"
#include "headers/Button.h"


int main(){
    std::string file = "levels/level1.txt";
    Level level(file);
    file = "levels/level2.txt";
    Level level2(file);

    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);

    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("img/title.jpg");
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

    Button button(sf::Vector2f(464, 450), "img/PLAY!_button.png");


    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        if(button.handle_button(window) == 1)
            break;
        window.display();
    }

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
    return 0;
}