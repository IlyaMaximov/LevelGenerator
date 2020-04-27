#ifndef LEVELGENERATOR_SPACEMANAGER_H
#define LEVELGENERATOR_SPACEMANAGER_H

#include <SFML/Graphics.hpp>

enum class GeomObj {
    Map,
    Minimap,
    SaveButton,
    OpenButton,
    RunButton,
    Palette,
};


class SpaceManager {
public:

    SpaceManager(const SpaceManager& ) = delete;
    SpaceManager(SpaceManager&& ) = delete;
    SpaceManager& operator=(SpaceManager& ) = delete;
    SpaceManager& operator=(SpaceManager&& ) = delete;

    explicit SpaceManager(size_t width = sf::VideoMode::getDesktopMode().width,
                          size_t height = sf::VideoMode::getDesktopMode().height) :
        desktop_width_(width),
        desktop_height_(height),
        guard_width_(desktop_width_ / 40),
        guard_height_(desktop_height_ / 30),
        map_width_(((desktop_width_ - 4 * guard_width_) / 160) * 128),
        map_height_(((desktop_height_ - 3 * guard_height_) / 32) * 32),
        minimap_width_(desktop_width_ - map_width_ - 4 * guard_width_),
        palette_height_((map_height_ - minimap_width_ - 2 * guard_height_) / 2),
        guard_button_((map_height_ - minimap_width_ - 2 * guard_height_ - palette_height_) / 8),
        button_height_((map_height_ - minimap_width_ - 2 * guard_height_ - palette_height_ - 2 * guard_button_) / 3) {};

    [[nodiscard]] sf::Vector2f getPos(GeomObj obj) const {
        switch (obj) {
            case GeomObj::Map :
                return sf::Vector2f(guard_width_, guard_height_);
            case GeomObj::Minimap :
                return sf::Vector2f(map_width_ + 2 * guard_width_,
                                    map_height_ + guard_height_ - minimap_width_);
            case GeomObj::Palette :
                return sf::Vector2f(map_width_ + 2 * guard_width_, guard_height_);
            case GeomObj::OpenButton :
                return sf::Vector2f(map_width_ + 2 * guard_width_, palette_height_ + 2 * guard_height_);
            case GeomObj::SaveButton :
                return sf::Vector2f(map_width_ + 2 * guard_width_,
                                    palette_height_ + 2 * guard_height_ + button_height_ + guard_button_);
            case GeomObj::RunButton :
                return sf::Vector2f(map_width_ + 2 * guard_width_,
                                    palette_height_ + 2 * guard_height_ + 2 * button_height_ + 2 * guard_button_);
        }
    }

    [[nodiscard]] sf::Vector2f getSize(GeomObj obj) const {
        switch (obj) {
            case GeomObj::Map :
                return sf::Vector2f(map_width_, map_height_);
            case GeomObj::Minimap :
                return sf::Vector2f(minimap_width_, minimap_width_);
            case GeomObj::Palette :
                return sf::Vector2f(minimap_width_, palette_height_);
            default:
                return sf::Vector2f(minimap_width_, button_height_);
        }
    }

private:
    const size_t desktop_width_;
    const size_t desktop_height_;
    const size_t guard_width_;
    const size_t guard_height_;
    const size_t map_width_;
    const size_t map_height_;
    const size_t minimap_width_;
    const size_t palette_height_;
    const size_t guard_button_;
    const size_t button_height_;
};

#endif //LEVELGENERATOR_SPACEMANAGER_H
