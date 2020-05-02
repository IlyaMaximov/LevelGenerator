#ifndef LEVELGENERATOR_TileMap_H
#define LEVELGENERATOR_TileMap_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "../Managers/TextureManager.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:

    explicit TileMap(sf::Vector2f position, sf::Vector2u tile_size, size_t width, size_t height,
        TextureManager* texture_manager, std::vector<TextureName>&& info = {});

    sf::Vector2f getPos() const {
        return pos_;
    }

    sf::Vector2f getSize() const {
        return sf::Vector2f(tile_size_.x * width_, tile_size_.y * height_);
    }

    sf::FloatRect getLocalBounds() const {
        return sf::FloatRect(getPos(), getSize());
    }

    sf::Vector2u getTileSize() const {
        return tile_size_;
    }

    sf::Vector2u getSizeInTiles() const {
        return sf::Vector2u(width_, height_);
    }

    TextureName getTextureName(int i, int j) const {
        return info_[get_index(i, j)];
    }

    TextureName getTextureName(int tile_num) const {
        return info_[tile_num];
    }

    const std::vector<TextureName>& getInfo() const {
        return info_;
    }

    void click(sf::Vector2f click_pos);
    void clear();
    void loadInfo(std::vector<TextureName>&&);


private:

    size_t get_index(size_t i, size_t j) const {
        assert(i < height_ && j < width_);
        return i * width_ + j;
    }

    void updateTileTexture(int tile_number);
    void drawBackground(sf::RenderTarget& target) const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2f pos_;
    size_t width_;
    size_t height_;
    sf::Vector2u tile_size_;
    sf::VertexArray m_vertices_;
    TextureManager* texture_manager_;
    std::vector<TextureName> info_{};
};


#endif //LEVELGENERATOR_TileMap_H
