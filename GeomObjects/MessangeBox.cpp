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

sf::FloatRect MessageBox::getLocalBounds() const {
    return sf::FloatRect(getPosition() - getOrigin(), getSize());
}

sf::Vector2f MessageBox::getSize() const {
    return text_box_.getSize();
}

std::string MessageBox::getUserText() const {
    return user_text_;
}

bool MessageBox::isFocused() const {
    return is_focused_;
}

bool MessageBox::textBoxFull() const{
    return output_text_.getLocalBounds().width + 18 > text_box_.getSize().x;
}

bool MessageBox::contains(sf::Vector2f pnt_) const {
    return getLocalBounds().contains(pnt_.x, pnt_.y);
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
    if (symbol == '\b') {
        if (!user_text_.empty()) {
            user_text_.pop_back();
        }
    } else if (symbol == '\r') {
        dynamic_cast<DialogWindow*>(window_)->EnterPressed(this);
    } else if (!textBoxFull()) {
        user_text_.push_back(symbol);
    }
    output_text_.setString(user_text_);
}

///////////////////////////////////////////

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

void MessageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text_box_, states);
    target.draw(output_text_, states);
}
