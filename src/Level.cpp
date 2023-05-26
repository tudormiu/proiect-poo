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
            walls.emplace_back(Position{x,y});
        }

    int number_of_landing_pads;
    file >> number_of_landing_pads;
    for (int i = 0; i < number_of_landing_pads; ++i) {
            int x, y;
            file >> x >> y;
            landing_pads.emplace_back(Position{x,y});
        }

    int number_of_boxes;
    file >> number_of_boxes;
    for (int i = 0; i < number_of_boxes; ++i) {
            int x, y;
            file >> x >> y;
            boxes.emplace_back(Position{x,y});
        }

    int player_x, player_y;
    file >> player_x >> player_y;

    this -> player = Player(Position{player_x, player_y});
    this -> player.power_up(1);

    this -> board = Board(lines, columns, walls, landing_pads, boxes, player);
}

int Level::handle_input(sf::RenderWindow &window) {

    enum state {
        back = -1,
        playing = 0,
        win = 1,
        lose = 2};

    float main_delay = 0.15f;
    float temp_delay = 0.05f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this -> board.move_player('a');

        window.clear();
        display_background(window);
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return win;

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
            display_background(window);
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return win;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this -> board.move_player('d');

        window.clear();
        display_background(window);
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return win;

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
            display_background(window);
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return win;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this -> board.move_player('w');

        window.clear();
        display_background(window);
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return win;

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
            display_background(window);
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return win;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this -> board.move_player('s');

        window.clear();
        display_background(window);
        this -> board.display_board(window);
        window.display();

        if(this -> board.check_win())
            return win;

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
            display_background(window);
            this -> board.display_board(window);
            window.display();

            if(this -> board.check_win())
                return win;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){}
        reset_level(*this);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){}
        return lose;
    }

    window.clear();

    display_background(window);

    int status = this -> board.display_board(window);

    if  (status == 1)
        reset_level(*this);

    if (status == 2)
        return back;

    window.display();

    if(this -> board.check_win())
        return win;
    return playing;
}

void Level::display_background(sf::RenderWindow &window) {
    sf::Sprite background_sprite;
    sf::Texture background_texture;
    background_texture.loadFromFile("img/background.jpg");
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(0, 0);
    window.draw(background_sprite);
}

int Level::display_level(sf::RenderWindow &window, Level level) {
    while (window.isOpen()) {
        window.clear();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int result = level.handle_input(window);
        if (result)
            return result;
    }
    return 0;
}

void Level::reset_level(Level &level) {
    Level temp_level(level.level_file_path);
    level = temp_level;
}
