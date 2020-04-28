#ifndef LEVELGENERATOR_MESSANGEBOX_H
#define LEVELGENERATOR_MESSANGEBOX_H

#include <iostream>

class MessageBox : public sf::Transformable, public sf::Drawable {
public:
    MessageBox(size_t max_char_cnt = 25) :
        char_cnt_bound_(max_char_cnt),
        text_box_(sf::Vector2f(15 * char_cnt_bound_, 25)) {

            if (!font_.loadFromFile("arial.ttf")) {
                throw std::runtime_error("It is not possible to load the font");
            }
            text_box_.setOutlineThickness(2);
            text_box_.setFillColor(sf::Color::White);
            text_box_.setOutlineColor(default_border_color_);
    }

    sf::FloatRect getLocalBounds() {
        return sf::FloatRect(getPosition() - getOrigin(), getSize());
    }

    sf::Vector2f getSize() const {
        return text_box_.getSize();
    }

    bool isFocused() const {
        return is_focused_;
    }

    bool contains(sf::Vector2f pnt_) {
        return getLocalBounds().contains(pnt_.x, pnt_.y);
    }

    void setFocus(bool focus) {
        is_focused_ = focus;
        if (is_focused_) {
            text_box_.setOutlineColor(focused_border_color_);
        } else {
            text_box_.setOutlineColor(default_border_color_);
        }
    }

    void handleInputChar(uint32_t symbol) {
        if (symbol == 8) {
            if (!user_text_.empty()) {
                user_text_.pop_back();
            }
        }
        else if (user_text_.size() < char_cnt_bound_) {
            user_text_.push_back(symbol);
        }
    }

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        target.draw(text_box_, states);
//        target.draw();
    }

    size_t char_cnt_bound_;
    sf::RectangleShape text_box_;
    sf::Font font_;
    std::string user_text_ = "";
    sf::Color default_border_color_ = sf::Color(127,127,127);
    sf::Color focused_border_color_ = sf::Color::Blue;
    bool is_focused_ = false;

};

#endif
