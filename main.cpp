#include <fstream>
#include <SFML/Graphics.hpp>
#include "headers/Level.h"
#include "headers/Button.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);

    Button button1(464, 460, std::string("PLAY!"),2);
    Button button2(464, 560, std::string("ERASE DATA"),2);

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
    for (int i = 0; i < 10; i++){
        level_buttons.emplace_back(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)),  std::to_string(i + 1), 3);
    }

    Menu level_menu(level_buttons, "img/background_levels.jpg");

    int pressed = Menu::display_menu(window, main_menu);

    if (pressed == 1) {
        int selected_level = Menu::display_menu(window, level_menu);
        if(selected_level)
            Level ::display_level(window, levels[selected_level - 1]);
    }
    else if (pressed == 2) {
        std::ofstream fout("game_data.txt");
        fout << "0";
        fout.close();
    }
    window.display();

    return 0;
}