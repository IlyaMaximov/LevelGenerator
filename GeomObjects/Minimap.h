#ifndef LEVELGENERATOR_MINIMAP_H
#define LEVELGENERATOR_MINIMAP_H

#include "TileMap.h"

#include <iostream>
#include <cassert>

class Minimap : public sf::Drawable, public sf::Transformable {
public:
    explicit Minimap(sf::Vector2f pos, sf::Vector2f size, TileMap* map) :
        map_(map),
        pos_(pos),
        size_(size) {};

private:

    void draw_background(sf::RenderTarget& target) const {
        sf::RectangleShape map_background(size_);
        map_background.setPosition(pos_);
        map_background.setFillColor(sf::Color::White);
        map_background.setOutlineThickness(1);
        map_background.setOutlineColor(sf::Color::Black);
        target.draw(map_background);
    }

    void setMinimap(TileMap& minimap) const {
        float x_compress = size_.x / map_->getSize().x;
        float y_compress = size_.y / map_->getSize().y;
        minimap.setScale(x_compress, y_compress);
        sf::Vector2f shift(map_->getPos().x * x_compress, map_->getPos().y * y_compress);
        minimap.move(pos_ - shift);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        TileMap minimap(*map_);
        setMinimap(minimap);
        draw_background(target);
        target.draw(minimap, states);
    }

    TileMap* map_;
    sf::Vector2f pos_;
    sf::Vector2f size_;
};

#endif //LEVELGENERATOR_MINIMAP_H
