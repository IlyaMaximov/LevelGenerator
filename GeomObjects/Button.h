#ifndef LEVELGENERATOR_BUTTON_H
#define LEVELGENERATOR_BUTTON_H

#include <SFML/Graphics.hpp>
#include "../Managers/TextureManager.h"
#include <cassert>

enum class ButtonStatus {
    Activated,
    Deactivated
};

class Button : public sf::Drawable, public sf::Transformable {

public:

    explicit Button(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* manager,
        TextureName texture = TextureName::Emptiness, const sf::Color& color = sf::Color());

    sf::Vector2f getPos() const;
    sf::Vector2f getSize() const;
    TextureName getTextureName() const;
    void setName(const std::string& name);
    virtual void click() = 0;

private:

    void nameConstructor();
    void spriteConstructor();
    void setTexture(TextureName texture);
    void setDefaultTexture(sf::Color color);
    void alignName();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
    sf::Vector2f pos_;
    sf::Vector2f size_;
    sf::RectangleShape sprite_;
    TextureManager* manager_;
    TextureName texture_name_;
    sf::Font font_;
    sf::Text name_{};
};


class LandscapeButton : public Button {
public:
    explicit LandscapeButton(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* manager, TextureName texture) :
        Button(pos, sizes, manager, texture, sf::Color()) {
            setStatus(ButtonStatus::Deactivated);
    };

    void click() override;

private:
    ButtonStatus status_ = ButtonStatus::Deactivated;

    void setStatus(ButtonStatus);
};

class SaveButton : public Button {
public:
    explicit SaveButton(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* manager,
            sf::Color color = sf::Color(), TextureName texture = TextureName::Emptiness):
        Button(pos, sizes, manager, texture,color) {
        setName("Save Current Map");
    };

    void click() override;
};

class OpenButton : public Button {
public:
    explicit OpenButton(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* manager,
            sf::Color color = sf::Color(), TextureName texture = TextureName::Emptiness):
        Button(pos, sizes, manager, texture, color) {
        setName("Open New Map");
    };

    void click() override;
};

class RunButton : public Button {
public:
    explicit RunButton(sf::Vector2f pos, sf::Vector2f sizes, TextureManager* manager,
            sf::Color color = sf::Color(), TextureName texture = TextureName::Emptiness):
        Button(pos, sizes, manager, texture, color) {
        setName("Run");
    };

    void click() override;
};


#endif
