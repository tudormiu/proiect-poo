#include <fstream>
#include <SFML/Graphics.hpp>
#include "headers/Level.h"
#include "headers/Button.h"
#include "headers/Menu.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);

    try{
        Big_button button1(464, 460, std::string("PLAY!"));
        Big_button button2(464, 560, std::string("ERASE DATA"));



    std::vector<Button> buttons_menu;
    buttons_menu.emplace_back(button1);
    buttons_menu.emplace_back(button2);

    Menu main_menu(buttons_menu);

    std::vector<Level> levels;
    levels.reserve(1000);
    levels.emplace_back(std::string("levels/level1.txt"));
    levels.emplace_back(std::string("levels/level2.txt"));
    levels.emplace_back(std::string("levels/level3.txt"));
    levels.emplace_back(std::string("levels/level4.txt"));
    levels.emplace_back(std::string("levels/level5.txt"));
    levels.emplace_back(std::string("levels/level6.txt"));
    levels.emplace_back(std::string("levels/level7.txt"));
    levels.emplace_back(std::string("levels/level8.txt"));
    levels.emplace_back(std::string("levels/level9.txt"));
    levels.emplace_back(std::string("levels/level10.txt"));

    std::vector<Button> level_buttons;
    level_buttons.reserve(1000);
    //for (int i = 0; i < 10; i++){
    //    level_buttons.emplace_back(Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)),   std::to_string(i + 1)));
    //}
    int i = 0;
    Square_button level1(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "1");
    i++;
    Square_button level2(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "2");
    i++;
    Square_button level3(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "3");
    i++;
    Square_button level4(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "4");
    i++;
    Square_button level5(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "5");
    i++;
    Square_button level6(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "6");
    i++;
    Square_button level7(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "7");
    i++;
    Square_button level8(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "8");
    i++;
    Square_button level9(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "9");
    i++;
    Square_button level10(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "10");

    level_buttons.emplace_back(level1);
    level_buttons.emplace_back(level2);
    level_buttons.emplace_back(level3);
    level_buttons.emplace_back(level4);
    level_buttons.emplace_back(level5);
    level_buttons.emplace_back(level6);
    level_buttons.emplace_back(level7);
    level_buttons.emplace_back(level8);
    level_buttons.emplace_back(level9);
    level_buttons.emplace_back(level10);

    Level_menu level_menu(level_buttons, "img/background_levels.jpg", true, false);


    bool updated = false;
    int pressed = 0;
    int selected_level = 0;
    while (window.isOpen()) {
        window.clear();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(!pressed)
            pressed = main_menu.display_menu(window);

        if (pressed == 1) {
            int unlocked_levels = 0;
            if(!updated) {
                std::ifstream data("game_data.txt");
                data >> unlocked_levels;
                level_menu.activate_buttons(unlocked_levels);
                updated = true;
            }

            if(selected_level == false)
                selected_level = level_menu.display_menu(window);

            if(selected_level == -1){
                pressed = 0;
                selected_level = 0;
                updated = false;
            }

            if(selected_level == -2){
                selected_level = 0;
            }

            if(selected_level > 0)
            {
                int status = Level ::display_level(window, levels[selected_level - 1]);
                if(status)
                {
                    if(status == 1)
                    {
                        std::ofstream fout("game_data.txt");
                        fout << std::max(unlocked_levels, selected_level);
                    }

                    selected_level = 0;
                    updated = false;
                }
            }
        }

        if (pressed == 2) {
            std::ofstream fout("game_data.txt");
            fout << "0";
            fout.close();
            pressed = 0;
            updated = false;
        }

        window.display();
    }
    }
    catch (eroare_aplicatie &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}