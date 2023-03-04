#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Position{
    int x_axis, y_axis;

public:
    Position(int xAxis, int yAxis) : x_axis(xAxis), y_axis(yAxis) {
        std::cout << "Constructor initializare poz\n";
    }
    Position(const Position& other) : x_axis{other.x_axis}, y_axis{other.y_axis} {
        std::cout << "Constructor copiere poz\n";
    }

    Position& operator=(const Position& other) {
        x_axis = other.x_axis;
        y_axis = other.y_axis;
        std::cout << "operator= copiere poz\n";
        return *this;
    }

    ~Position() {
        std::cout << "Destr poz\n";
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
        std::cout << "Constructor initializare zid\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Wall& st) {
        os << "Wall: " << st.position << "\n";
        return os;
    }

};

class Player{
    Position position;
    std::queue<char> inputs;

public:
    Player(const Position &position, const queue<char> &inputs) : position(position), inputs(inputs) {
        std::cout << "Constructor initializare juc\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& st) {
        os << "Position: " << st.position << "Pentru moment nu afisam coada de imputuri" <<"\n";
        return os;
    }

};

class Board{
    int lines, columns;
    std::vector<Wall> walls;
    Player player;

public:
    Board(int lines, int columns, const vector<Wall> &walls, Player player) : lines(lines), columns(columns),
                                                                                     walls(walls), player(std::move(player)) {
        std::cout << "Constructor initializare tabla\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Board& st) {
        os << "lines: " << st.lines << ", columns: " << st.columns << ", Player: " << st.player << "Pentru moment nu afisam vectorul de ziduri" <<"\n";
        return os;
    }

};

int main(){
    Position p1{1,2}, p2{5,0};
    Wall zid1{p2};
    std::vector<Wall> vector1;
    vector1.push_back(zid1);
    std::queue<char> coada;
    coada.push('a');
    Player jucator{p2,coada};
    Board tabla{10,10,vector1,jucator};

    std::cout<< "\n";
    std::cout << p1;
    std::cout << zid1;
    std::cout << jucator;
    std::cout << tabla;


    return 0;
}