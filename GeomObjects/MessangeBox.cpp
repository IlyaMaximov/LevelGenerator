#include "MessangeBox.h"
#include "../WindowObjects/DialogWindow.h"


MessageBox::MessageBox(sf::RenderWindow *init_window):
    window_(init_window),
    text_box_(sf::Vector2f(18 * 30, 25)) {

        if (!font_.loadFromFile("arial.ttf")) {
            throw std::runtime_error("It is not possible to load the font");
        }

        textBoxConstructor();
        outputTextConstructor();
}

void MessageBox::setFocus(bool focus) {
    is_focused_ = focus;
    if (is_focused_) {
        text_box_.setOutlineColor(focused_border_color_);
    } else {
        text_box_.setOutlineColor(default_border_color_);
    }
}

void MessageBox::handleInputChar(uint32_t symbol) {
    if (symbol == 8) {
        if (!user_text_.empty()) {
            user_text_.pop_back();
        }
    } else if (symbol == 13) {
        dynamic_cast<DialogWindow*>(window_)->EnterPressed(this);
    } else if (!textBoxFull()) {
        user_text_.push_back(symbol);
    }
    output_text_.setString(user_text_);
}

void MessageBox::textBoxConstructor() {
    text_box_.setOutlineThickness(2);
    text_box_.setFillColor(sf::Color::White);
    text_box_.setOutlineColor(default_border_color_);
}

void MessageBox::outputTextConstructor() {
    output_text_.setFont(font_);
    output_text_.setFillColor(sf::Color::Black);
    output_text_.setCharacterSize(20);
    output_text_.setPosition(text_box_.getPosition());
}

bool MessageBox::textBoxFull() {
    return output_text_.getLocalBounds().width + 18 > text_box_.getSize().x;
}



