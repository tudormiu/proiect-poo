#include "../headers/Button.h"

Button::Button(float x_axis, float y_axis, const std::string &text, const std::string &font_path,
               const std::string &texture_path_default, const std::string &texture_path_hover,
               const std::string &texture_path_disabled, int char_size,  bool active, float vertical_offset):
               x_axis(x_axis), y_axis(y_axis), active(active) {

    set_up(text, font_path, texture_path_default, texture_path_hover, texture_path_disabled, char_size, vertical_offset);

}

void Button::set_up(const std::string& text_, const std::string& font_path, const std::string& button_path_default,
                    const std::string& button_path_hover, const std::string& button_path_disabled, int char_size,
                    float vertical_offset){
    if(!font.loadFromFile(font_path))
        throw eroare_font(font_path);

    if(!this -> texture_default.loadFromFile(button_path_default))
        throw eroare_imagine(button_path_default);
    if(!this -> texture_hover.loadFromFile(button_path_hover))
        throw eroare_imagine(button_path_hover);
    if(!this -> texture_disabled.loadFromFile(button_path_disabled))
        throw eroare_imagine(button_path_disabled);

    this -> text.setCharacterSize(char_size);

    button_default.setTexture(texture_default);
    button_hover.setTexture(texture_hover);
    button_disabled.setTexture(texture_disabled);

    button_default.setPosition(x_axis, y_axis);
    button_hover.setPosition(x_axis, y_axis);
    button_disabled.setPosition(x_axis, y_axis);

    this -> text.setString(text_);
    this -> text.setFont(font);
    this -> text.setFillColor(sf::Color::White);

    center_text(vertical_offset);

    this -> text.setFont(font);

}

void Button::center_text(float vertical_offset) {
    sf::Vector2f center = {x_axis + (float(this -> texture_default.getSize().x) - this -> text.getGlobalBounds().getSize().x) / 2, y_axis + vertical_offset};
    this -> text.setPosition(center);
}

void Button::display_button(sf::RenderWindow &window, bool hover) {

    if (active){
        if(hover)
            window.draw(button_hover);
        else
            window.draw(button_default);

        window.draw(text);
    }
    else
        window.draw(button_disabled);
}

int Button::handle_button(sf::RenderWindow &window) {
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    bool hover = false;
    if(active){
        if (this -> check_parameters(mouse_position)) {
            hover = true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
                return 1;
            }
        }
    }
    display_button(window, hover);

    return 0;
}

void Button::set_active(Button *button, bool active_) {
    button -> active = active_;
}

std::ostream &operator<<(std::ostream &os, const Button &st) {
    os << "x_axis: " << st.x_axis << " y_axis: " << st.y_axis << " active: " << st.active;
    return os;
}

Button::~Button() = default;


Big_button::Big_button(float x_axis, float y_axis, const std::string &text, bool active):
        Button(x_axis, y_axis, text, "Minecraft.ttf", "img/buttons/big_button_default.png",
               "img/buttons/big_button_hover.png","img/buttons/big_button_disabled.png",
               46, active) {}

bool Big_button::check_parameters(sf::Vector2i mouse_position) {
    return (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < x_axis + 512 and
        float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < y_axis + 64);
}


Square_button::Square_button(float x_axis, float y_axis, const std::string &text, bool active):
        Button(x_axis, y_axis, text, "Minecraft.ttf", "img/buttons/square_button_default.png",
               "img/buttons/square_button_hover.png","img/buttons/square_button_disabled.png",
               80, active, 15) {}


bool Square_button::check_parameters(sf::Vector2i mouse_position) {
    return (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < x_axis + 128 and
            float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < y_axis + 128);
}


Back_button::Back_button(float x_axis, float y_axis, bool active):
        Button(x_axis, y_axis, "", "Minecraft.ttf", "img/buttons/back_button_default.png",
               "img/buttons/back_button_hover.png","img/buttons/small_square_button_disabled.png",
               46, active) {}

bool Back_button::check_parameters(sf::Vector2i mouse_position) {
    return (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < x_axis + 64 and
            float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < y_axis + 64);
}


Forward_button::Forward_button(float x_axis, float y_axis, bool active):
        Button(x_axis, y_axis, "", "Minecraft.ttf", "img/buttons/forward_button_default.png",
               "img/buttons/forward_button_hover.png","img/buttons/small_square_button_disabled.png",
               46, active) {}

bool Forward_button::check_parameters(sf::Vector2i mouse_position) {
    return (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < x_axis + 64 and
            float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < y_axis + 64);
}


Reset_button::Reset_button(float x_axis, float y_axis, bool active):
        Button(x_axis, y_axis, "", "Minecraft.ttf", "img/buttons/reset_button_default.png",
               "img/buttons/reset_button_hover.png","img/buttons/small_square_button_disabled.png",
               46, active) {}

bool Reset_button::check_parameters(sf::Vector2i mouse_position) {
    return (float(mouse_position.x) > this -> x_axis && float(mouse_position.x) < x_axis + 64 and
            float(mouse_position.y) > this -> y_axis && float(mouse_position.y) < y_axis + 64);
}