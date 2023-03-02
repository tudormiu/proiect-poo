#include <iostream>
#include <queue>

using namespace std;

class Position{
    int x_axis, y_axis;

public:
    Position(int xAxis, int yAxis) : x_axis(xAxis), y_axis(yAxis) {}

};

class Wall{
    Position position;

public:
    explicit Wall(const Position &position) : position(position) {}

};

class Player{
    Position position;
    std::queue<char> inputs;

public:
    Player(const Position &position, const queue<char> &inputs) : position(position), inputs(inputs) {}

};

class Board{
    int lines, columns;
    std::vector<Wall> walls;
    Player player;

public:
    Board(int lines, int columns, const vector<Wall> &walls, const Player &player) : lines(lines), columns(columns),
                                                                                     walls(walls), player(player) {}

};

int main(){
    Position p1{1,2}, p2{0,0};
    Wall zid1{p1};
    std::vector<Wall> vector1;
    vector1.push_back(zid1);
    std::queue<char> coada;
    coada.push('a');
    Player jucator{p2,coada};
    Board tabla{10,10,vector1,jucator};

    return 0;
}