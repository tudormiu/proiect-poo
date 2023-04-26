#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#include "Position.h"
#include <SFML/Graphics.hpp>


class Button {
    float x_limit, y_limit;

    sf::Texture texture_default, texture_hover, texture_disabled;
    sf::Sprite button_default, button_hover, button_disabled;
    sf::Font font;
    sf::Text text;

protected:
    float x_axis, y_axis;
    bool active;

public:

    Button(float x_axis, float y_axis, const std::string& text, const std::string& font_path,
                    const std::string& texture_path_default, const std::string& texture_path_hover,
                    const std::string& texture_path_disabled, int char_size,  bool active = true, float vertical_offset = 4.5);
    void set_up(const std::string& text_, const std::string& font_path, const std::string& texture_path_default,
                        const std::string& texture_path_hover, const std::string& texture_path_disabled, int char_size,
                        float vertical_offset = 4.5);
    void center_text(float vertical_offset = 0);
    void display_button(sf::RenderWindow &window, bool hover = false);
    virtual int handle_button(sf::RenderWindow &window);
    static void set_active(Button &buton, bool active_);
    static void set_active(Button *buton, bool active_);
    friend std::ostream &operator<<(std::ostream &os, const Button &st);
};

class Big_button : public Button {

public:
    explicit Big_button(float x_axis, float y_axis, const std::string& text, bool active = true);
    int handle_button(sf::RenderWindow &window) override;
};


class Square_button : public Button {
public:
    explicit Square_button(float x_axis, float y_axis, const std::string& text, bool active = true);
    int handle_button(sf::RenderWindow &window) override;
};


class Back_button : public Button {
public:
    explicit Back_button(float x_axis, float y_axis, bool active = true);
    int handle_button(sf::RenderWindow &window) override;
};


class Forward_button : public Button {
public:
    explicit Forward_button(float x_axis, float y_axis, bool active = true);
    int handle_button(sf::RenderWindow &window) override;
};


class Reset_button : public Button {
public:
    explicit Reset_button(float x_axis, float y_axis, bool active = true);
    int handle_button(sf::RenderWindow &window) override;
};

#endif //OOP_BUTTON_H
