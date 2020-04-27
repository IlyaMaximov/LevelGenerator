#ifndef LEVELGENERATOR_CLICKMANAGER_H
#define LEVELGENERATOR_CLICKMANAGER_H

#include "../GeomObjects/Button.h"
#include "../GeomObjects/TileMap.h"
#include "MouseStatus.h"

class ClickManager {
public:
    explicit ClickManager() = default;
    ClickManager(const ClickManager& ) = delete;
    ClickManager(ClickManager&& ) = delete;
    ClickManager& operator=(const ClickManager& ) = delete;
    ClickManager& operator=(ClickManager&& ) = delete;
    ~ClickManager() = default;

    void addButton(Button* button_ptr) {
        buttons_.emplace_back(button_ptr);
    }

    void deleteButton(Button* button_ptr) {
        for (size_t i = 0; i < buttons_.size(); ++i) {
            if (buttons_[i] == button_ptr) {
                buttons_.erase(buttons_.begin() + i);
                return ;
            }
        }
    }

    void addMap(TileMap* map_ptr) {
        map_ = map_ptr;
    }

    void deleteMap() {
        map_ = nullptr;
    }

    void checkClick(sf::Event& event, const sf::Vector2f& scale) const {
        sf::Vector2f pos;

        if ((event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
            && event.mouseButton.button == sf::Mouse::Left) {
            pos = {static_cast<float>(event.mouseButton.x) / scale.x, static_cast<float>(event.mouseButton.y) / scale.y};
            MouseStatus::setPressedStatus(event.type == sf::Event::MouseButtonPressed);
        } else if (event.type == sf::Event::MouseMoved) {
            pos = {static_cast<float>(event.mouseMove.x) / scale.x, static_cast<float>(event.mouseMove.y) / scale.y};
        } else {
            return;
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            checkButtonClick(event, pos);
        }
        if (MouseStatus::getPressedStatus()) {
            checkMapClick(event, pos);
        }
    }


private:

    void checkButtonClick(sf::Event& event, const sf::Vector2f& pos) const {
        for (auto& button : buttons_) {
            sf::FloatRect bounds(button->getPos(), button->getSize());
            if (bounds.contains(pos)) {
                button->click();
                return;
            }
        }
    }

    void checkMapClick(sf::Event& event, const sf::Vector2f& pos) const {
        if (map_ == nullptr || MouseStatus::getLandscapeButton() == nullptr) {
            return;
        }
        sf::FloatRect bounds(map_->getPos(), map_->getSize());
        if (bounds.contains(pos)) {
            map_->click(pos);
        }
    }

    std::vector<Button*> buttons_{};
    TileMap* map_{};
};

#endif
