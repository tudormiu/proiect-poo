#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "headers/Position.h"
#include "headers/Wall.h"
#include "headers/Player.h"
#include "headers/Board.h"
#include "headers/Box.h"


int main(){
    Position p1{1,2}, p2{5,0}, p3{3,3}, p4{4,4}, p5{1,3}, 
            p6{1,4}, p7{5,7};
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
    cutie1.set_status(false);
    std::vector<Box> vector_cutii;
    vector_cutii.push_back(cutie1);

    Player jucator{p6};
    Board tabla{10,10,vector_ziduri,vector_cutii,jucator};

    std::cout<< "\n";
    std::cout << p1;
    std::cout << zid1;
    std::cout << jucator;
    std::cout << tabla;


    jucator.power_up(10);

    char input_test = '0';
    while (input_test != 'r'){
        std::cin >> input_test;
        tabla.move_player(input_test);
        std::cout << tabla;
    }

    sf::RenderWindow window(sf::VideoMode(1080, 720), "My window", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}