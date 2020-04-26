#ifndef LEVELGENERATOR_PALETTE_H
#define LEVELGENERATOR_PALETTE_H

#include <vector>
#include "Button.h"
#include "../Managers/TextureManager.h"
#include "../Managers/SpaceManager.h"

class Palette : public sf::Drawable, public sf::Transformable {
public:

    explicit Palette(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* tex_manager, ClickManager* click_manager,
            const std::vector<TextureName>& landscapes = {}) :
        pos_(pos),
        size_(sizes),
        landscape_cnt_(landscapes.size() + 1),
        tex_manager_(tex_manager),
        click_manager_(click_manager) {

        if (!font_.loadFromFile("arial.ttf")) {
            throw std::runtime_error("It is not possible to load the font");
        }
        setName("Color Palette");

        sf::FloatRect button_size = static_cast<sf::FloatRect>(tex_manager_->getRect(TextureName::Grass));
        float shift = (size_.x - button_size.width * landscape_cnt_) / (static_cast<float>(landscape_cnt_) + 1);
        for (size_t i = 0; i < landscapes.size(); ++i) {
            sf::Vector2f button_pos = {pos_.x + (shift + button_size.width) * i + shift, pos_.y + size_.y / 2};
            landscape_buttons_.emplace_back(button_pos, sf::Vector2f(button_size.width, button_size.height),
                                            tex_manager_, landscapes[i]);
        }
        sf::Vector2f button_pos = {pos_.x + (shift + button_size.width) * landscapes.size() + shift, pos_.y + size_.y / 2};
        landscape_buttons_.emplace_back(button_pos, sf::Vector2f(button_size.width, button_size.height),
                                        tex_manager_, TextureName::Emptiness);
        for (auto& button : landscape_buttons_) {
            click_manager_->addButton(&button);
        }
    }

    Palette(const Palette& ) = delete;
    Palette(Palette&& ) = delete;
    Palette& operator =(const Palette& ) = delete;
    Palette& operator =(Palette&& ) = delete;


private:

    void setName(std::string&& name) {
        name_.setString("Color Palette");
        name_.setFont(font_);
        name_.setFillColor(sf::Color::Black);
        name_.setCharacterSize(27);
        name_.setStyle(sf::Text::Italic);
        alignName();
    }

    void alignName() {
        sf::FloatRect rect = name_.getGlobalBounds();
        sf::Vector2f rect_centre = sf::Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2);
        name_.setOrigin(rect_centre);
        sf::Vector2f button_centre = pos_ + sf::Vector2f(size_.x / 2, size_.y / 6);
        name_.setPosition(button_centre);
    }

    void drawBackground(sf::RenderTarget& target) const {
        sf::RectangleShape background(size_);
        background.setPosition(pos_);
        background.setFillColor(sf::Color(255, 250, 205));
        background.setOutlineThickness(1);
        background.setOutlineColor(sf::Color::Black);
        target.draw(background);

    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        drawBackground(target);
        target.draw(name_);
        for (const LandscapeButton& landscape_button: landscape_buttons_) {
            target.draw(landscape_button, states);
        }
    }

    sf::Vector2f pos_;
    sf::Vector2f size_;
    size_t landscape_cnt_;
    sf::Font font_;
    sf::Text name_;
    std::vector<LandscapeButton> landscape_buttons_;
    TextureManager* tex_manager_;
    ClickManager* click_manager_;
};

#endif
