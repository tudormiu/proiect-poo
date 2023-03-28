#include <SFML/Graphics.hpp>
#include "headers/Level.h"

int main(){
    std::string file = "levels/level1.txt";
    Level level(file);
    file = "levels/level2.txt";
    Level level2(file);

    sf::RenderWindow window(sf::VideoMode(704, 704), "My window", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        while(level.handle_input(window) == 0){}
        while(level2.handle_input(window) == 0){}
        break;
    }
    return 0;
}