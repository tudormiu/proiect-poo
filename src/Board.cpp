#include "../headers/Board.h"
#include "vector"

Board::Board(int lines, int columns, const std::vector<Wall> &walls, const std::vector<Landing_pad> &landing_pads,
             const std::vector<Box> &boxes, const Player& player) :
                lines(lines), columns(columns), walls(walls), landing_pads(landing_pads), boxes(boxes),
                player(player) {
    //std::cout << "Constructor initializare tabla\n";
    this -> offset_x = calculate_offset_x();
    this -> offset_y = calculate_offset_y();
}

Board::Board() {
    this -> lines = 0;
    this -> columns = 0;
    this -> offset_x = 0;
    this -> offset_y = 0;
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

//float Board::calculate_offset_x(sf::RenderWindow &window, float scale) const{
float Board::calculate_offset_x(float scale) const{
        //float offset_ = (float(window.getSize().x) - 64 * scale * float(this -> lines + 1)) / 2;
        float offset_ = (float(1440) - 64 * scale * float(this -> lines + 1)) / 2;
        return offset_;
}

//float Board::calculate_offset_y(sf::RenderWindow &window, float scale) const{
float Board::calculate_offset_y(float scale) const{
    //float offset_ = (float(window.getSize().y) - 64 * scale * float(this -> columns + 1)) / 2;
    float offset_ = (float(810) - 64 * scale * float(this -> columns + 1)) / 2;
    return offset_;
}

void Board::display_empty_board(sf::RenderWindow &window) const {

    //float offset_x = calculate_offset_x(window);
    //float offset_y = calculate_offset_y(window);
    try {
        Position temporary{1, 1};
        temporary.display_at_position(window, "img/tile.png", float(offset_x), float(offset_y), float(0.76),
                                      float(this->lines - 1), float(this->columns - 1));

        Position temp_00{0, 0};
        temp_00.display_at_position(window, "img/SS.png", offset_x, offset_y);

        Position temp_0c{0, columns};
        temp_0c.display_at_position(window, "img/SJ.png", offset_x, offset_y);

        Position temp_l0{lines, 0};
        temp_l0.display_at_position(window, "img/DS.png", offset_x, offset_y);

        Position temp_lc{lines, columns};
        temp_lc.display_at_position(window, "img/DJ.png", offset_x, offset_y);

        Position temp_s{1, 0};
        temp_s.display_at_position(window, "img/S.png", offset_x, offset_y, float(0.76), float(this->lines - 1));

        Position temp_j{1, columns};
        temp_j.display_at_position(window, "img/J.png", offset_x, offset_y, float(0.76), float(this->lines - 1));

        Position temp_sm{lines, 1};
        temp_sm.display_at_position(window, "img/SM.png", offset_x, offset_y, float(0.76), 1, float(this->columns - 1));

        Position temp_dm{0, 1};
        temp_dm.display_at_position(window, "img/DM.png", offset_x, offset_y, float(0.76), 1, float(this->columns - 1));
    }
    catch (eroare_imagine &err){
        std::cout << err.what() << std::endl;
    }

}

int Board::display_board(sf::RenderWindow &window) const {

    display_empty_board(window);

    Back_button back_button{0, 0, true};
    if(back_button.handle_button(window))
        return 2;

    Reset_button reset_button{100, 0, true};
    if(reset_button.handle_button(window))
        return 1;

    for (const Wall& wall: walls)
        wall.display_wall(window, offset_x, offset_y);
    for (const Landing_pad& landing_pad: landing_pads)
        landing_pad.display_landing_pad(window, offset_x, offset_y);
    for (const Box& box: boxes)
        box.display_box(window, offset_x, offset_y);
    player.display_player(window, offset_x, offset_y);

    return 0;
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



