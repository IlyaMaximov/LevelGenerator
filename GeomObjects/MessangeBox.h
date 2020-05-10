#ifndef LEVELGENERATOR_MESSANGEBOX_H
#define LEVELGENERATOR_MESSANGEBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WindowObj.h"

enum class MessageBoxType {
    Editable,
    NonEditable
};

class MessageBox : public WindowObj {
public:
    explicit MessageBox(sf::RenderWindow* init_window = nullptr, MessageBoxType = MessageBoxType::Editable,
            std::string&& initial_text = "", sf::Vector2f size = sf::Vector2f(540, 25));

    sf::FloatRect getLocalBounds() const;
    sf::Vector2f getSize() const;
    std::string getUserText() const;

    bool isFocused() const;
    bool textBoxFull() const;
    bool contains(sf::Vector2f pnt_) const;

    void setFocus(bool focus);
    void AcceptEvent(sf::Event&, const sf::Vector2f &pos) override;
    void handleInputChar(uint32_t symbol);


private:

    void textBoxConstructor();
    void outputTextConstructor();
    void alignOutputText();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f size_;
    MessageBoxType type_;
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
