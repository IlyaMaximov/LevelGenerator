#ifndef LEVELGENERATOR_TEXTUREMANAGER_H
#define LEVELGENERATOR_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <utility>
#include <iostream>

enum class TextureName {
    Grass,
    River,
    Tree,
    Gravel,
    Emptiness
};

class TextureManager {
public:

    TextureManager(const std::string&  file, const std::vector<std::pair<TextureName, sf::IntRect>>& data);

    TextureManager(const TextureManager&) = delete;
    TextureManager(TextureManager&&) = delete;
    TextureManager& operator=(TextureManager&) = delete;
    TextureManager& operator=(TextureManager&&) = delete;

    sf::IntRect getRect(TextureName name) const;
    const sf::Texture* getTexture(TextureName name) const;

    const sf::Texture* getAllTextures() const {
        return &all_textures_;
    }

private:

    struct TextureBlock {
        TextureBlock(TextureName name, const sf::IntRect& rectangle, const std::string& texture_file) :
                texture_name(name),
                borders(rectangle) {

            if (!texture.loadFromFile(texture_file, borders)) {
                throw std::runtime_error("File cannot be opened");
            }
        }

        TextureName texture_name;
        sf::IntRect borders;
        sf::Texture texture;
    };

    sf::Texture all_textures_;
    std::string texture_file_;
    std::vector<TextureBlock> data_;
};

#endif //LEVELGENERATOR_TEXTUREMANAGER_H
