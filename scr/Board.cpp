#include "../headers/Board.h"
#include "vector"

Board::Board(int lines, int columns, const std::vector<Wall> &walls, const std::vector<Box> &boxes, Player player) :
    lines(lines), columns(columns), walls(walls), boxes(boxes), player(std::move(player)) {
    //std::cout << "Constructor initializare tabla\n";
}

std::ostream &operator<<(std::ostream &os, const Board &st) {
    os << "lines: " << st.lines << ", columns: " << st.columns << "walls:" << "\n";
    for (const auto &wall: st.walls)
        os << wall;
    os <<"\n" << "boxes:" <<"\n";
    for (const auto &box: st.boxes)
        os << box;
    os << "Player: " << st.player << "\n";

    return os;
}

bool Board::box_collisions(char input_) {
    Position temp_{player.getPosition()};
    temp_.update_position(input_);
    for (Box &box: boxes) {
        if (box.check_collision(temp_)) {
            temp_.update_position(input_);
            if (temp_.position_outside_limits(lines, columns))
                return true;

            for (Wall wall: walls)
                if (wall.check_collision(temp_))
                    return true;

            for (Box other_box: boxes)
                if (other_box.check_collision(temp_))
                    return true;

            box.move(input_);
            player.move(input_);
            return true;
        }
    }
    return false;
}

void Board::move_player(char input_) {
    if (input_ != 'a' && input_ != 's' && input_ != 'd' && input_ != 'w')
        return;
    Position temp_{player.getPosition()};
    temp_.update_position(input_);
    if (temp_.position_outside_limits(lines, columns))
        return;
    if (!box_collisions(input_)) {
        for (Wall wall: walls) {
            if (wall.check_collision(temp_)) {
                return;
            }
        }
        player.move(input_);
    }
}


