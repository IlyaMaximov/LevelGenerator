#ifndef LEVELGENERATOR_LEVELGENERATOR_H
#define LEVELGENERATOR_LEVELGENERATOR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Managers/SpaceManager.h"
#include "Managers/ClickManager.h"
#include "GeomObjects/TileMap.h"
#include "GeomObjects/Palette.h"
#include "GeomObjects/Minimap.h"

class LevelGenerator : sf::RenderWindow {
public:
    explicit LevelGenerator(const std::vector<TextureName>& palette_landscapes, TextureManager* texture_manager,
                            SpaceManager* space_manager, ClickManager* click_manager,
                            const sf::VideoMode& window = sf::VideoMode::getDesktopMode()) :
        sf::RenderWindow(window,"Level Generator",sf::Style::Default,sf::ContextSettings(0, 0, 8)),
        texture_manager_(texture_manager),
        space_manager_(space_manager),
        click_manager_(click_manager),
        size_(sf::Vector2f(window.width, window.height)),
        map_(space_manager->getPos(GeomObj::Map), sf::Vector2f(32, 32),
             space_manager->getSize(GeomObj::Map).x / 32,
             space_manager->getSize(GeomObj::Map).y / 32,texture_manager_),
        minimap_(space_manager->getPos(GeomObj::Minimap), space_manager->getSize(GeomObj::Minimap), &map_),
        palette_(space_manager->getPos(GeomObj::Palette), space_manager->getSize(GeomObj::Palette),
                texture_manager_, click_manager_, palette_landscapes) {


        sf::Color button_color = sf::Color(135, 206, 250);
        Button* save_button = new SaveButton(space_manager->getPos(GeomObj::SaveButton),
                                             space_manager->getSize(GeomObj::SaveButton),
                                             texture_manager_, button_color);

        Button* open_button = new OpenButton(space_manager->getPos(GeomObj::OpenButton),
                                             space_manager->getSize(GeomObj::OpenButton),
                                             texture_manager_, button_color);

        Button* run_button = new RunButton(space_manager->getPos(GeomObj::RunButton),
                                           space_manager->getSize(GeomObj::RunButton),
                                           texture_manager_, button_color);

        service_buttons_ = {save_button, open_button, run_button};

        click_manager_->addMap(&map_);
        for (auto& button : service_buttons_) {
            click_manager_->addButton(button);
        }
    };

    LevelGenerator(const LevelGenerator& ) = delete;
    LevelGenerator(LevelGenerator&& ) = delete;
    LevelGenerator& operator =(const LevelGenerator& ) = delete;
    LevelGenerator& operator =(LevelGenerator&& ) = delete;

    ~LevelGenerator() override {
        for (Button* service_button: service_buttons_) {
            delete service_button;
        }
    }

    void run() {
        while (isOpen()) {
            sf::Event event{};
            while (pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    close();
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f scale = {getSize().x / size_.x, getSize().y / size_.y};
                    click_manager_->checkClick(event, scale);
                }
            }
            clear(sf::Color(240, 240, 240));

            draw(minimap_);
            draw(map_);
            draw(palette_);
            for (auto button: service_buttons_) {
                draw(*button);
            }
            display();
        }
    }


private:

    TextureManager* texture_manager_;
    SpaceManager* space_manager_;
    ClickManager* click_manager_;
    sf::Vector2f size_;
    TileMap map_;
    Minimap minimap_;
    Palette palette_;
    std::vector<Button*> service_buttons_;
};

#endif