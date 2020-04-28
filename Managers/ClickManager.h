#ifndef LEVELGENERATOR_CLICKMANAGER_H
#define LEVELGENERATOR_CLICKMANAGER_H

#include "../GeomObjects/Button.h"
#include "../GeomObjects/TileMap.h"
#include "../GeomObjects/MessangeBox.h"
#include "MouseStatus.h"

class ClickManager {
public:
    explicit ClickManager() = default;
    ClickManager(const ClickManager& ) = delete;
    ClickManager(ClickManager&& ) = delete;
    ClickManager& operator=(const ClickManager& ) = delete;
    ClickManager& operator=(ClickManager&& ) = delete;
    ~ClickManager() = default;

    void addButton(Button* button_ptr, sf::RenderWindow* window_ptr) {
        buttons_.emplace_back(button_ptr, window_ptr);
    }

    void deleteButton(Button* button_ptr, sf::RenderWindow* window_ptr) {
        for (size_t i = 0; i < buttons_.size(); ++i) {
            if (buttons_[i].window_ptr == window_ptr && buttons_[i].obj_ptr == button_ptr) {
                buttons_.erase(buttons_.begin() + i);
                return ;
            }
        }
    }

    void addMap(TileMap* map_ptr, sf::RenderWindow* window_ptr) {
        maps_.emplace_back(map_ptr, window_ptr);
    }

    void deleteMap(TileMap* map_ptr, sf::RenderWindow* window_ptr) {
        for (size_t i = 0; i < maps_.size(); ++i) {
            if (maps_[i].window_ptr == window_ptr && maps_[i].obj_ptr == map_ptr) {
                maps_.erase(maps_.begin() + i);
                return ;
            }
        }
    }

    void addMessageBox(MessageBox* ptr, sf::RenderWindow* window_ptr) {
        message_boxes_.emplace_back(ptr, window_ptr);
    }

    void deleteMessageBox(MessageBox* ptr, sf::RenderWindow* window_ptr) {
        for (size_t i = 0; i < message_boxes_.size(); ++i) {
            if (message_boxes_[i].window_ptr == window_ptr && message_boxes_[i].obj_ptr == ptr) {
                message_boxes_.erase(message_boxes_.begin() + i);
                return ;
            }
        }
    }

    void checkEvents(sf::Event& event, const sf::Vector2f& scale, sf::RenderWindow* window_ptr) const {
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
            checkButtonClick(event, pos, window_ptr);
        }
        if (MouseStatus::getPressedStatus()) {
            checkMapPressed(event, pos, window_ptr);
        }
        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::TextEntered) {
            checkMessageBoxClick(event, pos, window_ptr);
        }
    }


private:

    template<typename T>
    struct WindowObj {

        WindowObj(T* obj, sf::RenderWindow* window) :
            obj_ptr(obj),
            window_ptr(window) {};

        T* obj_ptr;
        sf::RenderWindow* window_ptr;
    };

    void checkButtonClick(sf::Event& event, const sf::Vector2f& pos, sf::RenderWindow* window_ptr) const {
        for (auto& button : buttons_) {
            if (button.window_ptr != window_ptr) {
                return;
            }
            if (button.obj_ptr->getLocalBounds().contains(pos)) {
                button.obj_ptr->click();
                return;
            }
        }
    }

    void checkMapPressed(sf::Event& event, const sf::Vector2f& pos, sf::RenderWindow* window_ptr) const {
        for (auto map : maps_) {
            if (map.window_ptr != window_ptr || MouseStatus::getLandscapeButton() == nullptr) {
                return;
            }
            if (map.obj_ptr->getLocalBounds().contains(pos)) {
                map.obj_ptr->click(pos);
            }
        }
    }

    void checkMessageBoxClick(sf::Event& event, const sf::Vector2f& pos, sf::RenderWindow* window_ptr) const {
        for (auto message_box : message_boxes_) {
            if (message_box.window_ptr != window_ptr) {
                return;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << pos.x << " " << pos.y << std::endl;
                message_box.obj_ptr->setFocus(message_box.obj_ptr->contains(pos));
            } else if (event.type == sf::Event::TextEntered && message_box.obj_ptr->isFocused()) {
                message_box.obj_ptr->handleInputChar(event.text.unicode);
            }
        }
    }

    std::vector<WindowObj<Button>> buttons_{};
    std::vector<WindowObj<TileMap>> maps_{};
    std::vector<WindowObj<MessageBox>> message_boxes_{};
};

#endif
