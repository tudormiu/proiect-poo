#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "headers/Position.h"
#include "headers/Wall.h"
#include "headers/Player.h"
#include "headers/Board.h"
#include "headers/Box.h"


int main(){
    Position p1{1,2}, p2{5,1}, p3{3,3}, p4{4,4}, p5{1,3},
            p6{1,4}, p7{5,7}, p8{8, 7};
    Wall zid1{p1};
    Wall zid2{p2};
    Wall zid3{p3};
    Wall zid4{p4};
    Wall zid5{p5};
    std::vector<Wall> vector_ziduri;
    vector_ziduri.push_back(zid1);
    vector_ziduri.push_back(zid2);
    vector_ziduri.push_back(zid3);
    vector_ziduri.push_back(zid4);
    vector_ziduri.push_back(zid5);
    
    Box cutie1{p7};
    Box cutie2{p8};
    cutie1.set_status(false);
    std::vector<Box> vector_cutii;
    vector_cutii.push_back(cutie1);
    vector_cutii.push_back(cutie2);

    Player jucator{p6};
    Board tabla{10,10,vector_ziduri,vector_cutii,jucator};

    std::cout<< "\n";
    std::cout << p1;
    std::cout << zid1;
    std::cout << jucator;
    std::cout << tabla;

    jucator.power_up(10);

    sf::RenderWindow window(sf::VideoMode(704, 704), "My window", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float main_delay = 0.3f;
        float temp_delay = 0.07f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            tabla.move_player('a');

            window.clear();
            tabla.display_board(window);
            window.display();

            sf::Clock main_clock;
            sf::Clock temp_clock;

            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sf::Time main_elapsed = main_clock.getElapsedTime();
                if (main_elapsed.asSeconds() > main_delay)
                {
                sf::Time temp_elapsed = temp_clock.getElapsedTime();
                    if (temp_elapsed.asSeconds() > temp_delay) {
                        tabla.move_player('a');
                        temp_clock.restart();
                    }
                }
                window.clear();
                tabla.display_board(window);
                window.display();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            tabla.move_player('d');

            window.clear();
            tabla.display_board(window);
            window.display();

            sf::Clock main_clock;
            sf::Clock temp_clock;

            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sf::Time main_elapsed = main_clock.getElapsedTime();
                if (main_elapsed.asSeconds() > main_delay)
                {
                    sf::Time temp_elapsed = temp_clock.getElapsedTime();
                    if (temp_elapsed.asSeconds() > temp_delay) {
                        tabla.move_player('d');
                        temp_clock.restart();
                    }
                }
                window.clear();
                tabla.display_board(window);
                window.display();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            tabla.move_player('w');

            window.clear();
            tabla.display_board(window);
            window.display();

            sf::Clock main_clock;
            sf::Clock temp_clock;

            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sf::Time main_elapsed = main_clock.getElapsedTime();
                if (main_elapsed.asSeconds() > main_delay)
                {
                    sf::Time temp_elapsed = temp_clock.getElapsedTime();
                    if (temp_elapsed.asSeconds() > temp_delay) {
                        tabla.move_player('w');
                        temp_clock.restart();
                    }
                }
                window.clear();
                tabla.display_board(window);
                window.display();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            tabla.move_player('s');

            window.clear();
            tabla.display_board(window);
            window.display();

            sf::Clock main_clock;
            sf::Clock temp_clock;

            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sf::Time main_elapsed = main_clock.getElapsedTime();
                if (main_elapsed.asSeconds() > main_delay)
                {
                    sf::Time temp_elapsed = temp_clock.getElapsedTime();
                    if (temp_elapsed.asSeconds() > temp_delay) {
                        tabla.move_player('s');
                        temp_clock.restart();
                    }
                }
                window.clear();
                tabla.display_board(window);
                window.display();
            }
        }

        window.clear();
        tabla.display_board(window);
        window.display();
    }



    return 0;
}