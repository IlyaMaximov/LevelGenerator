#ifndef LEVELGENERATOR_MESSANGEBOX_H
#define LEVELGENERATOR_MESSANGEBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>

class MessageBox : public sf::Transformable, public sf::Drawable {
public:
    explicit MessageBox(sf::RenderWindow* init_window);

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

    std::string getUserText() {
        return user_text_;
    }

    void setFocus(bool focus);
    void handleInputChar(uint32_t symbol);

private:

    void textBoxConstructor();
    void outputTextConstructor();
    bool textBoxFull();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        target.draw(text_box_, states);
        target.draw(output_text_, states);
    }


    std::string user_text_ = "";
    sf::Font font_;
    sf::Text output_text_;
    sf::RectangleShape text_box_;

    sf::RenderWindow* window_ = nullptr;
    sf::Color default_border_color_ = sf::Color(127,127,127);
    sf::Color focused_border_color_ = sf::Color::Blue;
    bool is_focused_ = false;
};

#endif
