#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    float x_axis, y_axis, x_limit, y_limit;

    bool active;

    sf::Texture texture_default, texture_hover, texture_disabled;
    sf::Sprite button_default, button_hover, button_disabled;
    sf::Font font;
    sf::Text text;

public:

    Button(float x_axis, float y_axis, const std::string& text, const std::string& font_path,
                    const std::string& texture_path_default, const std::string& texture_path_hover,
                    const std::string& texture_path_disabled, int char_size,  bool active = true, float vertical_offset = 4.5);
    void set_up(const std::string& text_, const std::string& font_path, const std::string& texture_path_default,
                        const std::string& texture_path_hover, const std::string& texture_path_disabled, int char_size,
                        float vertical_offset = 4.5);
    void center_text(float vertical_offset = 0);
    void display_button(sf::RenderWindow &window, bool hover = false);
    int handle_button(sf::RenderWindow &window);
    static void set_active(Button &buton, bool active_);
    friend std::ostream &operator<<(std::ostream &os, const Button &st);
};

class Standard_button : public Button {
public:
    explicit Standard_button(float x_axis, float y_axis, const std::string& text, bool active = true);
};


class Big_button : public Button {

public:
    explicit Big_button(float x_axis, float y_axis, const std::string& text, bool active = true);
};


class Square_button : public Button {
public:
    explicit Square_button(float x_axis, float y_axis, const std::string& text, bool active = true);
};


class Back_button : public Button {
public:
    explicit Back_button(float x_axis, float y_axis, bool active = true);
};


class Forwad_button : public Button {
public:
    explicit Forwad_button(float x_axis, float y_axis, bool active = true);
};


class Reset_button : public Button {
public:
    explicit Reset_button(float x_axis, float y_axis, bool active = true);
};

#endif //OOP_BUTTON_H
