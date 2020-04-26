#ifndef LEVELGENERATOR_TileMap_H
#define LEVELGENERATOR_TileMap_H

#include <SFML/Graphics.hpp>
#include "../Managers/TextureManager.h"
#include "../Managers/MouseStatus.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:

    explicit TileMap(sf::Vector2f position, sf::Vector2f tile_size, size_t width, size_t height,
        TextureManager* texture_manager, std::vector<TextureName>&& info = {}) :
        pos_(position),
        tile_size_(tile_size),
        width_(width),
        height_(height),
        texture_manager_(texture_manager),
        m_vertices_(sf::VertexArray(sf::Quads, width_ * height_ * 4)) {

            if (info.size() == width_ * height_) {
                info_ = std::move(info);
            } else {
                info_.resize(width_ * height_, TextureName::Emptiness);
            }

            for (size_t i = 0; i < height_; ++i)
                for (size_t j = 0; j < width_; ++j) {

                    int tile_number = get_index(i, j);
                    sf::Vertex* quad = &m_vertices_[tile_number * 4];

                    quad[0].position = pos_ + sf::Vector2f(j * tile_size_.x, i * tile_size_.y);
                    quad[1].position = pos_ + sf::Vector2f((j + 1) * tile_size_.x, i * tile_size_.y);
                    quad[2].position = pos_ + sf::Vector2f((j + 1) * tile_size_.x, (i + 1) * tile_size_.y);
                    quad[3].position = pos_ + sf::Vector2f(j * tile_size_.x, (i + 1) * tile_size_.y);

                    updateTileTexture(tile_number);
                }
    }

    sf::Vector2f getPos() const {
        return pos_;
    }

    sf::Vector2f getSize() const {
        return sf::Vector2f(tile_size_.x * width_, tile_size_.y * height_);
    }

    void Click(sf::Vector2f click_pos) {
        click_pos -= pos_;
        int tile_number = get_index(click_pos.y / tile_size_.y, click_pos.x / tile_size_.x);
        info_[tile_number] = MouseStatus::getLandscape();
        updateTileTexture(tile_number);
    }

private:

    size_t get_index(int i, int j) const {
        assert(i < height_ && j < width_);
        return i * width_ + j;
    }

    void updateTileTexture(int tile_number) {
        sf::Vertex* quad = &m_vertices_[tile_number * 4];
        sf::IntRect tex_rect = texture_manager_->getRect(info_[tile_number]);
        quad[0].texCoords = sf::Vector2f(tex_rect.left, tex_rect.top);
        quad[1].texCoords = sf::Vector2f(tex_rect.left + tex_rect.width, tex_rect.top);
        quad[2].texCoords = sf::Vector2f(tex_rect.left + tex_rect.width, tex_rect.top + tex_rect.height);
        quad[3].texCoords = sf::Vector2f(tex_rect.left + tex_rect.width, tex_rect.top);
    }

    void drawBackground(sf::RenderTarget& target) const {
        sf::RectangleShape map_background(sf::Vector2f(width_ * tile_size_.x, height_ * tile_size_.y));
        map_background.setPosition(pos_);
        map_background.setFillColor(sf::Color::White);
        map_background.setOutlineThickness(1);
        map_background.setOutlineColor(sf::Color::Black);
        target.draw(map_background);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        drawBackground(target);
        states.texture = texture_manager_->getAllTextures();
        target.draw(m_vertices_, states);
    }

    sf::Vector2f pos_;
    size_t width_;
    size_t height_;
    sf::Vector2u tile_size_;
    sf::VertexArray m_vertices_;
    TextureManager* texture_manager_;
    std::vector<TextureName> info_{};
};


#endif //LEVELGENERATOR_TileMap_H
