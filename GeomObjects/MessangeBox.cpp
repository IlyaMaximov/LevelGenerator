#include "MessangeBox.h"
#include "../WindowObjects/DialogWindow.h"

MessageBox::MessageBox(sf::RenderWindow *init_window, MessageBoxType type, std::string&& initial_text, sf::Vector2f size):
    window_(init_window),
    size_(size),
    type_(type),
    text_box_(size),
    user_text_(std::move(initial_text)) {

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

void MessageBox::setSize(const sf::Vector2f& size) {
    size_ = size;
    text_box_.setSize(size);
    if (type_ == MessageBoxType::NonEditable) {
        alignOutputText();
    }
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

void MessageBox::AcceptEvent(sf::Event &event, const sf::Vector2f &pos) {
    if (type_ != MessageBoxType::Editable) {
        return;
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        setFocus(contains(pos));
    } else if (event.type == sf::Event::TextEntered && isFocused()) {
        handleInputChar(event.text.unicode);
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
    output_text_.setString(user_text_);
    if (type_ == MessageBoxType::NonEditable) {
        alignOutputText();
    }
}

void MessageBox::alignOutputText() {
    sf::FloatRect rect = output_text_.getLocalBounds();
    sf::Vector2f rect_centre = sf::Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2);
    output_text_.setOrigin(rect_centre);
    sf::Vector2f button_centre = sf::Vector2f(size_.x / 2, size_.y / 2);
    output_text_.setPosition(button_centre);
}

void MessageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text_box_, states);
    target.draw(output_text_, states);
}