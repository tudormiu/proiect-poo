#include "../headers/Level.h"
#include <fstream>

Level::Level(const std::string& level_file_path): level_file_path(level_file_path){
    std::ifstream file(level_file_path);

    int level_number_;
    file >> level_number_;
    level_number = level_number_;
    std::cout<<level_number;

    int lines_, columns_;
    file >> lines_ >> columns_;
    lines = lines_;
    columns = columns_;

    int number_of_walls;
    file >> number_of_walls;
    for (int i = 0; i < number_of_walls; ++i) {
            int x, y;
            file >> x >> y;
            walls.push_back(Wall(Position{x,y}));
        }

    int number_of_landing_pads;
    file >> number_of_landing_pads;
    for (int i = 0; i < number_of_landing_pads; ++i) {
            int x, y;
            file >> x >> y;
            landing_pads.push_back(Landing_pad(Position{x,y}));
        }

    int number_of_boxes;
    file >> number_of_boxes;
    for (int i = 0; i < number_of_boxes; ++i) {
            int x, y;
            file >> x >> y;
            boxes.push_back(Box(Position{x,y}));
        }

    int player_x, player_y;
    file >> player_x >> player_y;

    this -> player = Player(Position{player_x, player_y});

    this -> board = Board(lines, columns, walls, landing_pads, boxes, player);
}

int Level::handle_input(sf::RenderWindow &window) {
    float main_delay = 0.3f;
    float temp_delay = 0.07f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this -> board.move_player('a');

        window.clear();
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return 1;

        sf::Clock main_clock;
        sf::Clock temp_clock;

        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sf::Time main_elapsed = main_clock.getElapsedTime();
            if (main_elapsed.asSeconds() > main_delay)
            {
                sf::Time temp_elapsed = temp_clock.getElapsedTime();
                if (temp_elapsed.asSeconds() > temp_delay) {
                    this -> board.move_player('a');
                    temp_clock.restart();
                }
            }
            window.clear();
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return 1;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this -> board.move_player('d');

        window.clear();
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return 1;

        sf::Clock main_clock;
        sf::Clock temp_clock;

        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            sf::Time main_elapsed = main_clock.getElapsedTime();
            if (main_elapsed.asSeconds() > main_delay)
            {
                sf::Time temp_elapsed = temp_clock.getElapsedTime();
                if (temp_elapsed.asSeconds() > temp_delay) {
                    this -> board.move_player('d');
                    temp_clock.restart();
                }
            }
            window.clear();
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return 1;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this -> board.move_player('w');

        window.clear();
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return 1;

        sf::Clock main_clock;
        sf::Clock temp_clock;

        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            sf::Time main_elapsed = main_clock.getElapsedTime();
            if (main_elapsed.asSeconds() > main_delay)
            {
                sf::Time temp_elapsed = temp_clock.getElapsedTime();
                if (temp_elapsed.asSeconds() > temp_delay) {
                    this -> board.move_player('w');
                    temp_clock.restart();
                }
            }
            window.clear();
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return 1;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this -> board.move_player('s');

        window.clear();
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return 1;

        sf::Clock main_clock;
        sf::Clock temp_clock;

        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            sf::Time main_elapsed = main_clock.getElapsedTime();
            if (main_elapsed.asSeconds() > main_delay)
            {
                sf::Time temp_elapsed = temp_clock.getElapsedTime();
                if (temp_elapsed.asSeconds() > temp_delay) {
                    this -> board.move_player('s');
                    temp_clock.restart();
                }
            }
            window.clear();
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return 1;
        }
    }

    window.clear();
    this -> board.display_board(window);
    window.display();

    if(this -> board.check_win())
        return 1;
    return 0;

}
