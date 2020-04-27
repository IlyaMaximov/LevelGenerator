#ifndef LEVELGENERATOR_DIALOGWINDOW_H
#define LEVELGENERATOR_DIALOGWINDOW_H

#include "SFML/Graphics.hpp"
#include "../GeomObjects/MessangeBox.h"


class DialogWindow : public sf::RenderWindow {
public:
    explicit DialogWindow(std::string&& message):
        sf::RenderWindow(sf::VideoMode(600, 300),"Dialog window",sf::Style::Titlebar|sf::Style::Close,sf::ContextSettings(0, 0, 8)),
        size_(sf::Vector2u(600, 300)),
        message_(std::move(message)) {
        size_t x_centre = (sf::VideoMode::getDesktopMode().width - size_.x) / 2;
        size_t y_centre = (sf::VideoMode::getDesktopMode().height - size_.y) / 2;
        setPosition(sf::Vector2i(x_centre, y_centre));
    };

    void run() {
        while (isOpen()) {
            sf::Event event{};
            while (pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    close();
            }
            clear(sf::Color(240, 240, 240));

            display();
        }
    }

private:
    const sf::Vector2u size_;
    std::string message_;
};


#endif //LEVELGENERATOR_DIALOGWINDOW_H