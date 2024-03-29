#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    sf::Texture texture_default, texture_hover, texture_disabled;
    sf::Sprite button_default, button_hover, button_disabled;
    sf::Font font;
    sf::Text text;

protected:
    Position<float> position;
    bool active;

public:


    Button(float x_axis, float y_axis, const std::string& text, const std::string& font_path,
                    const std::string& texture_path_default, const std::string& texture_path_hover,
                    const std::string& texture_path_disabled, int char_size,  bool active = true, float vertical_offset = 4.5);

    virtual ~Button() = 0;

    void set_up(const std::string& text_, const std::string& font_path, const std::string& texture_path_default,
                        const std::string& texture_path_hover, const std::string& texture_path_disabled, int char_size,
                        float vertical_offset = 4.5);
    void center_text(float vertical_offset = 0);
    void display_button(sf::RenderWindow &window, bool hover = false);
    int handle_button(sf::RenderWindow &window);
    virtual bool check_parameters(sf::Vector2i mouse_position) = 0;
    void set_active(bool active_);
    friend std::ostream &operator<<(std::ostream &os, const Button &st);
};

class Big_button : public Button {

public:
    explicit Big_button(float x_axis, float y_axis, const std::string& text, bool active = true);
    bool check_parameters(sf::Vector2i mouse_position) override;
};


class Square_button : public Button {
public:
    explicit Square_button(float x_axis, float y_axis, const std::string& text, bool active = true);
    bool check_parameters(sf::Vector2i mouse_position) override;
};

class Small_square_button : public Button {
public:
    explicit Small_square_button(float x_axis, float y_axis, const std::string& texture_default, const std::string& texture_hover, bool active = true);
    bool check_parameters(sf::Vector2i mouse_position) override;
};

class Back_button : public Small_square_button {
public:
    Back_button(float x_axis, float y_axis, bool active = true);
};


class Forward_button : public Small_square_button {
    Forward_button(float x_axis, float y_axis, bool active = true);
public:
    Forward_button(const Forward_button&) = delete;
    Forward_button& operator=(const Forward_button&) = delete;
    static Forward_button* get_forward_button_pointer() {
        static auto* button = new Forward_button(1256, 492);
        return button;
    }
};


class Reset_button : public Small_square_button {
public:
    explicit Reset_button(float x_axis, float y_axis, bool active = true);
};

class Button_factory {
public:
    static Square_button* level_button(int position);
    static Big_button* menu_button(int y_axis, const std::string& string);
    static Back_button* back_button();
};

#endif //OOP_BUTTON_H
