#include <iostream>
#include "LevelGenerator.h"
#include "Managers/ClickManager.h"

std::vector<std::pair<TextureName, sf::IntRect>> get_marking() {
    std::vector<std::pair<TextureName, sf::IntRect>> data(5);
    for (int i = 0; i < 5; ++i) {
        data[i].first = static_cast<TextureName>(i);
        data[i].second = sf::IntRect(i * 32, 0, 32, 32);
    }
    return data;
}

int main() {
    size_t window_width = 1400;  //sf::VideoMode::getDesktopMode().width
    size_t window_height = 900;  //sf::VideoMode::getDesktopMode().height
    sf::VideoMode window = sf::VideoMode(window_width, window_height);

    try {
        std::string textures_file = "terrains.png";
        TextureManager texture_manager(textures_file, get_marking());
        SpaceManager space_manager(window_width, window_height);
        ClickManager click_manager;
        std::vector<TextureName>palette_landscapes
            = {TextureName::Grass, TextureName::Gravel, TextureName::River, TextureName::Tree, TextureName::Emptiness};

        LevelGenerator generator(palette_landscapes, &texture_manager, &space_manager, &click_manager, window);
        generator.run();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    return 0;
}
