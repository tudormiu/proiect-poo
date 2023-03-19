#include <iostream>
#include <queue>
#include <utility>
#include <SFML/Graphics.hpp>
#include <fstream>


class Position{
    int x_axis, y_axis;

public:
    Position(int xAxis, int yAxis) : x_axis(xAxis), y_axis(yAxis) {
        //std::cout << "Constructor initializare poz\n";
    }
    Position(const Position& other) : x_axis{other.x_axis}, y_axis{other.y_axis} {
        //std::cout << "Constructor copiere poz\n";
    }

    Position& operator=(const Position& other) {
        x_axis = other.x_axis;
        y_axis = other.y_axis;
        //std::cout << "operator= copiere poz\n";
        return *this;
    }

    ~Position() {
        //std::cout << "Destr poz\n";
    }

    static void updatePosition(Position &position_, char input_) {
        position_.x_axis = position_.x_axis + (input_ == 'd' ? 1 : (input_ == 'a' ? -1 : 0));
        position_.y_axis = position_.y_axis + (input_ == 'w' ? 1 : (input_ == 's' ? -1 : 0));
    }

    static bool comparing(Position const& position1_, Position  const& position2_){
        if (position1_.x_axis == position2_.x_axis && position1_.y_axis == position2_.y_axis)
            return true;
        return false;
    }

    static bool positionInLimits(Position const& position_, int down_, int right_){
        if (position_.x_axis >= 0 && position_.x_axis < down_ && position_.y_axis >= 0 && position_.y_axis < right_)
            return true;
        std::cout << "Ai atins limita tablei\n";
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Position& st) {
        os << "x_axis: " << st.x_axis << ", y_axis: " << st.y_axis << "\n";
        return os;
    }

};

class Wall{
    Position position;

public:
    explicit Wall(const Position &position) : position(position) {
        //std::cout << "Constructor initializare zid\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Wall& st) {
        os << "Wall: " << st.position;
        return os;
    }

    static bool checkCollision(Position const& position_, Wall const& wall_){
        if (Position::comparing(position_, wall_.position))
        {
            std::cout << "Ai lovit un zid\n";
            return true;
        }
        return false;
    }

};

class Player{
    Position position;

public:
    explicit Player(const Position &position) : position(position){
        //std::cout << "Constructor initializare juc\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& st) {
        os << "Position: " << st.position << "\n";
        return os;
    }

    [[nodiscard]] const Position &getPosition() const {
        return position;
    }

};

class Board {
    int lines, columns;
    std::vector<Wall> walls;
    Player player;

public:
    Board(int lines, int columns, const std::vector<Wall> &walls, Player player) : lines(lines), columns(columns),
                                                                              walls(walls), player(std::move(player)) {
        //std::cout << "Constructor initializare tabla\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Board &st) {
        os << "lines: " << st.lines << ", columns: " << st.columns << "\nPlayer " << st.player << "walls:" << "\n";
        for (const auto &wall: st.walls)
            os << wall;

        return os;
    }

    void movePlayer(char input_){
        if (input_ != 'a' && input_ != 's' && input_ != 'd' && input_ != 'w')
            return;
        Position temp_{player.getPosition()};
        Position::updatePosition(temp_, input_);
        bool colision = false;
        for (const auto & wall : walls) {
            if (Wall::checkCollision(temp_, const_cast<Wall &>(wall))) {
                colision = true;
                break;
            }
            if (!Position::positionInLimits(temp_, lines, columns)) {
                colision = true;
                break;
            }

        }
        if (!colision)
            Position::updatePosition(const_cast<Position &>(player.getPosition()), input_);
    }

};

int main(){
    Position p1{1,2}, p2{5,0}, p3{3,3}, p4{4,4}, p5{1,3}, p6{1,4};
    Wall zid1{p1};
    Wall zid2{p2};
    Wall zid3{p3};
    Wall zid4{p4};
    Wall zid5{p5};
    std::vector<Wall> vector1;
    vector1.push_back(zid1);
    vector1.push_back(zid2);
    vector1.push_back(zid3);
    vector1.push_back(zid4);
    vector1.push_back(zid5);

    Player jucator{p6};
    Board tabla{10,10,vector1,jucator};

    std::cout<< "\n";
    std::cout << p1;
    std::cout << zid1;
    std::cout << jucator;
    std::cout << tabla;

    std::ifstream fin("tastatura.txt");
    char input_test;
    while (fin >> input_test){
        tabla.movePlayer(input_test);
        std::cout << tabla;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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