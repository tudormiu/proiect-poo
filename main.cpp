#include <fstream>
#include <SFML/Graphics.hpp>
#include "headers/Level.h"
#include "headers/Button.h"
#include "headers/Menu.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);

        try{

        Button * button1 = new Big_button(464, 460, std::string("PLAY!"));
        Button * button2 = new Big_button(464, 560, std::string("ERASE DATA"));

        Forward_button fb(1256, 492);
        Back_button bb(120, 492);

        std::vector<Button*> buttons_menu;
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

        std::vector<Button*> level_buttons;
        level_buttons.reserve(1000);
        for (int i = 0; i < 10; i++){
            level_buttons.emplace_back(Button_factory::level_button(i));
        }

//        int i = 0;
//        Button * level1 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "1");
//        i++;
//        Button * level2 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "2");
//        i++;
//        Button * level3 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "3");
//        i++;
//        Button * level4 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "4");
//        i++;
//        Button * level5 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "5");
//        i++;
//        Button * level6 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "6");
//        i++;
//        Button * level7 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "7");
//        i++;
//        Button * level8 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "8");
//        i++;
//        Button * level9 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "9");
//        i++;
//        Button * level10 = new Square_button(256 + float(200 * int(i % 5)), 360 + float(200 * int(i / 5)), "10");

//        int i = 0;
//        Button * level1 = Button_factory::level_button(i);
//        i++;
//        Button * level2 = Button_factory::level_button(i);
//        i++;
//        Button * level3 = Button_factory::level_button(i);
//        i++;
//        Button * level4 = Button_factory::level_button(i);
//        i++;
//        Button * level5 = Button_factory::level_button(i);
//        i++;
//        Button * level6 = Button_factory::level_button(i);
//        i++;
//        Button * level7 = Button_factory::level_button(i);
//        i++;
//        Button * level8 = Button_factory::level_button(i);
//        i++;
//        Button * level9 = Button_factory::level_button(i);
//        i++;
//        Button * level10 = Button_factory::level_button(i);


//        level_buttons.emplace_back(level1);
//        level_buttons.emplace_back(level2);
//        level_buttons.emplace_back(level3);
//        level_buttons.emplace_back(level4);
//        level_buttons.emplace_back(level5);
//        level_buttons.emplace_back(level6);
//        level_buttons.emplace_back(level7);
//        level_buttons.emplace_back(level8);
//        level_buttons.emplace_back(level9);
//        level_buttons.emplace_back(level10);

        Level_menu level_menu(level_buttons, "img/background_levels.jpg", true, false, &bb, &fb);


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

            //pressed functioneaza pentru meniul principal cu codurile 1(play) sau 2(erase data)
            if(!pressed)
                pressed = main_menu.display_menu(window);

            int number_of_levels = 0;
            std::ifstream number_data("game_data.txt");
                number_data >> number_of_levels;
            number_data.close();

            // 1(play)
            if (pressed == 1) {
                int unlocked_levels = 0;
                if(!updated) {
                    std::ifstream data("game_data.txt");
                    data >> number_of_levels >> unlocked_levels;
                    level_menu.activate_buttons(unlocked_levels);
                    updated = true;
                }

                //selected_level functioneaza pentru meniul de nivele cu codurile
                // 0 default
                // 1-10(nivel selectat)
                // -1(back)
                // -2(forward), but we don't hava an additional menu for this yet.
                if(selected_level == 0)
                    selected_level = level_menu.display_menu(window);

                // -1(back)
                if(selected_level == -1){
                    pressed = 0;
                    selected_level = 0;
                    updated = false;
                }

                // -2(forward) n/
                if(selected_level == -2){
                    selected_level = 0;
                }

                // 1-10(nivel selectat)
                if(selected_level > 0)
                {
                    int status = Level ::display_level(window, levels[selected_level - 1]);
                    if(status)
                    {
                        if(status == 1)
                        {
                            std::ofstream fout("game_data.txt");
                            fout << number_of_levels << '\n' << std::min(number_of_levels - 1, std::max(unlocked_levels, selected_level));
                        }

                        selected_level = 0;
                        updated = false;
                    }
                }
            }

            // 2(erase data)
            if (pressed == 2) {
                std::ofstream fout("game_data.txt");
                fout << number_of_levels << "\n0";
                fout.close();
                pressed = 0;
                updated = false;
            }

            window.display();
        }

        delete button1;
        delete button2;
//        delete level1;
//        delete level2;
//        delete level3;
//        delete level4;
//        delete level5;
//        delete level6;
//        delete level7;
//        delete level8;
//        delete level9;
//        delete level10;

          for (auto & temp : level_buttons)
              delete temp;

    }
    catch (eroare_aplicatie &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}