#include "Button.h"
#include "../Managers/MouseStatus.h"
#include "../WindowObjects/DialogWindow.h"
#include <fstream>

Button::Button(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* manager, TextureName texture, const sf::Color& color) :
    pos_(pos),
    size_(sizes),
    texture_name_(texture),
    manager_(manager) {

        if (!font_.loadFromFile("arial.ttf")) {
            throw std::runtime_error("It is not possible to load the font");
        }
        nameConstructor();
        spriteConstructor();

        if (texture != TextureName::Emptiness) {
            setTexture(texture);
        } else {
            setDefaultTexture(color);
        }
}

void Button::nameConstructor() {
    name_.setFont(font_);
    name_.setFillColor(sf::Color::Black);
    name_.setCharacterSize(25);
    name_.setStyle(sf::Text::Italic);
}

void Button::spriteConstructor() {
    sprite_.setSize(size_);
    sprite_.setPosition(pos_);
    sprite_.setOutlineThickness(1);
    sprite_.setOutlineColor(sf::Color::Black);
}

sf::Vector2f Button::getPos() const {
    return pos_;
}

sf::Vector2f Button::getSize() const {
    return size_;
}

sf::FloatRect Button::getLocalBounds() const {
    return sf::FloatRect(getPos(), getSize());
}

TextureName Button::getTextureName() const {
    return texture_name_;
}

void Button::setName(const std::string &name) {
    name_.setString(name);
    alignName();
    fontSizeNormalize();
}

void Button::setDefaultTexture(sf::Color color) {
    sprite_.setFillColor(color);
}

void Button::setTexture(TextureName texture) {
    sprite_.setTexture(manager_->getTexture(texture), false);
}

void Button::alignName() {
    sf::FloatRect rect = name_.getGlobalBounds();
    sf::Vector2f rect_centre = sf::Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2);
    name_.setOrigin(rect_centre);
    sf::Vector2f button_centre = sprite_.getPosition() +
                                 sf::Vector2f(sprite_.getSize().x / 2, sprite_.getSize().y / 2);
    name_.setPosition(button_centre);
}

void Button::fontSizeNormalize() {
    float scale_aspect_x = 0.9f * (size_.x / name_.getLocalBounds().width);
    float scale_aspect_y = 0.8f * (size_.y / name_.getLocalBounds().height);
    float scale_aspect = std::min(1.f, std::min(scale_aspect_x, scale_aspect_y));
    name_.setScale(scale_aspect, scale_aspect);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = manager_->getAllTextures();
    target.draw(sprite_, states);
    if (name_.getString() != "") {
        target.draw(name_, states);
    }
}


///////////////////////////////////////////////////

void LandscapeButton::setStatus(ButtonStatus new_status_) {
    sf::Color new_color = sprite_.getFillColor();
    status_ = new_status_;
    if (status_ == ButtonStatus::Activated) {
        new_color.a = 255;
        sprite_.setFillColor(new_color);
    } else {
        new_color.a = 150;
        sprite_.setFillColor(new_color);
    }
}

void LandscapeButton::click() {
    if (status_ == ButtonStatus::Deactivated) {
        setStatus(ButtonStatus::Activated);
        MouseStatus::setLandscapeButton(this);
    } else {
        setStatus(ButtonStatus::Deactivated);
        MouseStatus::setLandscapeButton(nullptr);
    }
}

void SaveButton::click() {
    std::string file_name;
    DialogWindow ask_window("What do you want to name this map?", &file_name, nullptr);
    ask_window.run();
    write_map(std::move(file_name));
}

void OpenButton::click() {
    std::string file_name;
    DialogWindow window("What file do you want to open?", &file_name, nullptr);
    window.run();
    read_map(std::move(file_name));
}

void ClearButton::click() {
    map_->clear();
}

void SaveButton::write_map(std::string &&file_name) const {
    std::ofstream file_out(file_name);
    file_out << map_->getSizeInTiles().x << " " << map_->getSizeInTiles().y << '\n';
    for (size_t i = 0; i < map_->getSizeInTiles().y; ++i) {
        for (size_t j = 0; j < map_->getSizeInTiles().x; ++j) {
            file_out << static_cast<size_t>(map_->getTextureName(i, j)) << " ";
        }
        file_out << "\n";
    }
    file_out.close();
}

void OpenButton::read_map(std::string &&file_name) const {
    sf::Vector2u map_size;
    std::ifstream file_in(file_name);
    if (!file_in.is_open()) {
        throw std::runtime_error("Error open file");
    }
    file_in >> map_size.x >> map_size.y;
    /////////////////////////////////////////////////////////
    if (map_->getSizeInTiles() != map_size) {
        throw std::runtime_error("Error map size");
    }
    ///////////////////////////////////////////////////
    std::vector<TextureName> map_info(map_size.x * map_size.y);
    for (size_t i = 0; i < map_size.x * map_size.y; ++i) {
        int texture_id;
        file_in >> texture_id;
        map_info[i] = static_cast<TextureName>(texture_id);
    }
    map_->loadInfo(std::move(map_info));
    file_in.close();
}