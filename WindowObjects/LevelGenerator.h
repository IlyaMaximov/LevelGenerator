#ifndef LEVELGENERATOR_LEVELGENERATOR_H
#define LEVELGENERATOR_LEVELGENERATOR_H

#include <SFML/Graphics.hpp>
#include "../Managers/SpaceManager.h"
#include "../Managers/ClickManager.h"
#include "../Managers/TextureManager.h"
#include "../GeomObjects/TileMap.h"
#include "../GeomObjects/Palette.h"
#include "../GeomObjects/Minimap.h"

class LevelGenerator : sf::RenderWindow {
public:
    explicit LevelGenerator(const std::vector<TextureName>& palette_landscapes, TextureManager* texture_manager,
            const sf::VideoMode& window = sf::VideoMode::getDesktopMode(), ClickManager* click_manager = nullptr);

    LevelGenerator(const LevelGenerator& ) = delete;
    LevelGenerator(LevelGenerator&& ) = delete;
    LevelGenerator& operator =(const LevelGenerator& ) = delete;
    LevelGenerator& operator =(LevelGenerator&& ) = delete;

    ~LevelGenerator() override {
        for (Button* service_button: service_buttons_) {
            delete service_button;
        }
        if (init_click_manager_) {
            delete click_manager_;
        }
    }

    void run();


private:

    void alignWindow();

    sf::Vector2f size_;
    TextureManager* texture_manager_;
    SpaceManager space_manager_;
    bool init_click_manager_ = false;
    ClickManager* click_manager_;
    TileMap map_;
    Minimap minimap_;
    Palette palette_;
    std::vector<Button*> service_buttons_;
};

#endif