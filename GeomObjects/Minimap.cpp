#include "Minimap.h"

void Minimap::draw_background(sf::RenderTarget &target) const {
    sf::RectangleShape map_background(size_);
    map_background.setPosition(pos_);
    map_background.setFillColor(sf::Color::White);
    map_background.setOutlineThickness(1);
    map_background.setOutlineColor(sf::Color::Black);
    target.draw(map_background);
}

void Minimap::setMinimap(TileMap &minimap) const {
    float x_compress = size_.x / map_->getSize().x;
    float y_compress = size_.y / map_->getSize().y;
    minimap.setScale(x_compress, y_compress);
    sf::Vector2f shift(map_->getPos().x * x_compress, map_->getPos().y * y_compress);
    minimap.move(pos_ - shift);
}

void Minimap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    TileMap minimap(*map_);
    setMinimap(minimap);

    draw_background(target);
    target.draw(minimap, states);
}
