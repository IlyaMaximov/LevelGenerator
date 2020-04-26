#include <iostream>
#include "WindowObjects/LevelGenerator.h"

std::vector<std::pair<TextureName, sf::IntRect>> get_marking() {
    std::vector<std::pair<TextureName, sf::IntRect>> data(4);
    for (int i = 0; i < 4; ++i) {
        data[i].first = static_cast<TextureName>(i);
        data[i].second = sf::IntRect(i * 32, 0, 32, 32);
    }
    return data;
}

int main() {
    size_t window_width = 1200;
    size_t window_height = 800;
    sf::VideoMode window = sf::VideoMode(window_width, window_height);

    try {
        std::string textures_file = "terrains.png";
        TextureManager texture_manager(textures_file, get_marking());
        std::vector<TextureName>palette_landscapes
            = {TextureName::Grass, TextureName::Tree, TextureName::Gravel, TextureName::River};

        LevelGenerator generator(palette_landscapes, &texture_manager, window);
        generator.run();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    return 0;
}