#include <fstream>
#include <SFML/Graphics.hpp>
#include "headers/Level.h"
#include "headers/Button.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);

    Button button1(sf::Vector2f(464, 460), std::string("PLAY!"),2);
    Button button2(sf::Vector2f(464, 560), std::string("ERASE DATA"),2);

    std::vector<Button> buttons_menu;
    buttons_menu.emplace_back(button1);
    buttons_menu.emplace_back(button2);

    Menu main_menu(buttons_menu);

    std::vector<Level> levels;
    levels.emplace_back(std::string("levels/level1.txt"));
    levels.emplace_back(std::string("levels/level2.txt"));
    levels.emplace_back(std::string("levels/level3.txt"));
    levels.emplace_back(std::string("levels/level4.txt"));
    levels.emplace_back(std::string("levels/level5.txt"));
    levels.emplace_back(std::string("levels/level6.txt"));

    std::vector<Button> level_buttons;
    for (int i = 0; i < 6; i++){
        level_buttons.emplace_back(sf::Vector2f(800, 260 + 100 * float(i)), std::string("LEVEL " + std::to_string(i + 1)),1);
    }

    Menu level_menu(level_buttons);

    int pressed = 0;
    while (window.isOpen()) {
        window.clear();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        pressed = main_menu.handle_menu(window);
        if (pressed) {
            break;
        }
    }

    int selected_level = 0;
    if (pressed == 1) {
        while (window.isOpen()) {
            window.clear();
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            selected_level = level_menu.handle_menu(window);
            if (selected_level) {
                break;
            }
        }
        if(selected_level) {
            while (window.isOpen()) {
                window.clear();
                sf::Event event{};
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                    if(levels[selected_level - 1].handle_input(window) == 2)
                        break;
            }
        }
    }
    else if (pressed == 2) {
        std::ofstream fout("game_data.txt");
        fout << "0";
        fout.close();
    }
    window.display();

    return 0;
}