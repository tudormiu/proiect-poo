#include <SFML/Graphics.hpp>
#include "headers/Level.h"

int main(){
    Level level{"levels/level1.txt"};

    sf::RenderWindow window(sf::VideoMode(704, 704), "My window", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        level.handle_input(window);
    }

    return 0;
}