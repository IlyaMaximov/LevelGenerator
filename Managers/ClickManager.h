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

    void addButton(Button* button_ptr, sf::RenderWindow* window_ptr);
    void addMap(TileMap* map_ptr, sf::RenderWindow* window_ptr);
    void addMessageBox(MessageBox* ptr, sf::RenderWindow* window_ptr);

    void deleteButton(Button* button_ptr, sf::RenderWindow* window_ptr);
    void deleteMap(TileMap* map_ptr, sf::RenderWindow* window_ptr);
    void deleteMessageBox(MessageBox* ptr, sf::RenderWindow* window_ptr);

    void checkEvents(sf::Event& event, const sf::Vector2f& scale, sf::RenderWindow* window_ptr) const ;

private:

    template<typename T>
    struct WindowObj {

        WindowObj(T* obj, sf::RenderWindow* window) :
            obj_ptr(obj),
            window_ptr(window) {};

        T* obj_ptr;
        sf::RenderWindow* window_ptr;
    };

    void checkButtonClick(sf::Event& event, const sf::Vector2f& pos, sf::RenderWindow* window_ptr) const;
    void checkMapPressed(sf::Event& event, const sf::Vector2f& pos, sf::RenderWindow* window_ptr) const;
    void checkMessageBoxClick(sf::Event& event, const sf::Vector2f& pos, sf::RenderWindow* window_ptr) const;

    std::vector<WindowObj<Button>> buttons_{};
    std::vector<WindowObj<TileMap>> maps_{};
    std::vector<WindowObj<MessageBox>> message_boxes_{};
};

#endif
