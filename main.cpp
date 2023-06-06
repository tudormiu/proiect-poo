#include <fstream>
#include <SFML/Graphics.hpp>
#include "headers/Level.h"
#include "headers/Button.h"
#include "headers/Menu.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1440, 810), "My window", sf::Style::Titlebar | sf::Style::Close);

        try{
        std::vector<Button*> buttons_menu;
        buttons_menu.emplace_back(Button_factory::menu_button(460, std::string("PLAY!")));
        buttons_menu.emplace_back(Button_factory::menu_button(560, std::string("ERASE DATA")));

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

        Button * back_button = Button_factory::back_button();
        Button * forward_button = Forward_button::get_forward_button_pointer();

        Level_menu level_menu(level_buttons, "img/background_levels.jpg", true, false,
                              back_button, forward_button);

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

        for (auto & temp : buttons_menu)
            delete temp;

        for (auto & temp : level_buttons)
            delete temp;

        delete back_button;
        delete forward_button;

    }
    catch (eroare_aplicatie &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}