#ifndef OOP_POSITION_H
#define OOP_POSITION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Exceptions.h"

template<class Type> class Position{
    Type x_axis, y_axis;

public:

    Position(Type xAxis, Type yAxis) : x_axis(xAxis), y_axis(yAxis) {
        //std::cout << "Constructor initializare poz\n";
    }

    Position(const Position<Type>& other) = default;

    Position& operator=(const Position<Type>& other) = default;

    ~Position() = default;

    bool comparing(Position<Type> const& position1_, Position<Type>  const& position2_){
        return position1_.x_axis == position2_.x_axis && position1_.y_axis == position2_.y_axis;
    }

    [[nodiscard]] bool position_outside_limits(const int down_, const int right_) const{
        if (this -> x_axis > 0 && this -> x_axis < down_ && this -> y_axis > 0 && this -> y_axis < right_)
            return false;
        std::cout << "Ai atins limita tablei\n";
        return true;
    }

    void update_position(const char input_) {
        this -> x_axis = this -> x_axis + (input_ == 'd' ? 1 : (input_ == 'a' ? -1 : 0));
        this -> y_axis = this -> y_axis + (input_ == 's' ? 1 : (input_ == 'w' ? -1 : 0));
    }

    friend std::ostream &operator<<(std::ostream &os, const Position &st){
        os << "x_axis: " << st.x_axis << ", y_axis: " << st.y_axis << "\n";
        return os;
    }

    void display_at_position(sf::RenderWindow &window, const std::string& texture_path, float offset_x = 0,
                             float offset_y = 0, float scale = 0.76, float scale_x = 1, float scale_y = 1) const {
        sf::Sprite sprite;
        sf::Texture texture;
        if(!texture.loadFromFile(texture_path))
            throw eroare_imagine(texture_path);
        sprite.setTexture(texture);
        sprite.setPosition(((float(this -> x_axis) * 64) * scale) + offset_x,((float(this -> y_axis) * 64) * scale) + offset_y);
        sprite.setScale(scale_x * scale, scale_y * scale);
        window.draw(sprite);
    }

    [[maybe_unused]] void display_at_position(sf::RenderWindow &window, sf::Sprite& sprite) const {
        sprite.setPosition(((float(this -> x_axis) * 64)),((float(this -> y_axis) * 64)));
        window.draw(sprite);
    }

    [[nodiscard]] Type get_x_axis() const {
        return this -> x_axis;
    }

    [[nodiscard]] Type get_y_axis() const {
        return this -> y_axis;
    }

};

#endif //OOP_POSITION_H
