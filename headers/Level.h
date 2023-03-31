#ifndef OOP_LEVEL_H
#define OOP_LEVEL_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Wall.h"
#include "Player.h"
#include "Box.h"
#include "Landing_pad.h"

class Level {
    Board board;
    std::vector<Wall> walls;
    std::vector<Landing_pad> landing_pads;
    std::vector<Box> boxes;
    Player player;

    int level_number;
    int lines, columns;


    std::string level_file_path;

    public:

    explicit Level(const std::string& level_file_path);
    int handle_input(sf::RenderWindow &window);
    static void display_background(sf::RenderWindow &window);
    static int display_level(sf::RenderWindow &window, Level level);
    static void reset_level(Level &level);
};

#endif //OOP_LEVEL_H
