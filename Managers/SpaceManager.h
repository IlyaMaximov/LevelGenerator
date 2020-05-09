#ifndef LEVELGENERATOR_SPACEMANAGER_H
#define LEVELGENERATOR_SPACEMANAGER_H

#include <SFML/Graphics.hpp>

enum class GeomObjType {
    Map,
    Minimap,
    SaveButton,
    OpenButton,
    RunButton,
    Palette,
};


class SpaceManager {
public:
    explicit SpaceManager(size_t width = sf::VideoMode::getDesktopMode().width,
                          size_t height = sf::VideoMode::getDesktopMode().height);
    SpaceManager(const SpaceManager& ) = delete;
    SpaceManager(SpaceManager&& ) = delete;
    SpaceManager& operator=(SpaceManager& ) = delete;
    SpaceManager& operator=(SpaceManager&& ) = delete;

    [[nodiscard]] sf::Vector2f getPos(GeomObjType obj) const;
    [[nodiscard]] sf::Vector2f getSize(GeomObjType obj) const;

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
