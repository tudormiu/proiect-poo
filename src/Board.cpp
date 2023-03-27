#include "../headers/Board.h"
#include "vector"

Board::Board(int lines, int columns, const std::vector<Wall> &walls, const std::vector<Landing_pad> &landing_pads,
             const std::vector<Box> &boxes, Player player) :
                lines(lines), columns(columns), walls(walls), landing_pads(landing_pads), boxes(boxes),
                player(std::move(player)) {
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

            box.move(input_, landing_pads);
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

void Board::display_empty_board(sf::RenderWindow &window) const {
    for (int i = 0; i <= this -> lines; i++){
        for (int j = 0; j <= this -> columns; j++) {
            if (i == 0){
                if (j == 0){
                    Position temp_{i, j};
                    temp_.display_at_position(window, "img/SS.png");
                }
                else if (j == columns){
                    Position temp_{i, j};
                    temp_.display_at_position(window,"img/SJ.png");
                }
                else{
                    Position temp_{i, j};
                    temp_.display_at_position(window,"img/SM.png");
                }
            }
            else if (i == lines){
                if (j == 0){
                    Position temp_{i, j};
                    temp_.display_at_position(window,"img/DS.png");
                }
                else if (j == columns){
                    Position temp_{i, j};
                    temp_.display_at_position(window,"img/DJ.png");
                }
                else{
                    Position temp_{i, j};
                    temp_.display_at_position(window,"img/DM.png");
                }

            }
            else if (j == 0){
                Position temp_{i, j};
                temp_.display_at_position(window,"img/S.png");
            }
            else if (j == columns){
                Position temp_{i, j};
                temp_.display_at_position(window,"img/J.png");
            }
            else{
                Position temp_{i, j};
                temp_.display_at_position(window,"img/tile.png");
            }
        }
    }
}

void Board::display_board(sf::RenderWindow &window) const {
    display_empty_board(window);
    for (const Wall& wall: walls)
        wall.display_wall(window);
    for (const Landing_pad& landing_pad: landing_pads)
        landing_pad.display_landing_pad(window);
    for (const Box& box: boxes)
        box.display_box(window);
    player.display_player(window);
}

bool Board::check_win() const {
    for (const Box& box: this -> boxes)
        if (!box.get_status())
            return false;
    for (const Landing_pad& landing_pad: this -> landing_pads)
        if (!landing_pad.is_active())
            return false;
    return true;
}



