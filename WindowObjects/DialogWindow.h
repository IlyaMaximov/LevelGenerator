#ifndef LEVELGENERATOR_DIALOGWINDOW_H
#define LEVELGENERATOR_DIALOGWINDOW_H

#include "SFML/Graphics.hpp"
#include "../GeomObjects/MessangeBox.h"
#include "../Managers/ClickManager.h"
#include <iostream>


class DialogWindow : public sf::RenderWindow {
public:
    explicit DialogWindow(std::string&& message, ClickManager* click_manager):
        sf::RenderWindow(sf::VideoMode(500, 200),"Dialog window",sf::Style::Titlebar|sf::Style::Close,sf::ContextSettings(0, 0, 8)),
        size_(sf::Vector2u(500, 200)),
        click_manager_(click_manager) {

        if (!font_.loadFromFile("arial.ttf")) {
            throw std::runtime_error("It is not possible to load the font");
        }
        alignWindow();
        queryConstructor(std::move(message));
        responseConstructor();

        click_manager_->addMessageBox(&message_box_, this);
    };

    void run() {
        while (isOpen()) {
            sf::Event event{};
            while (pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    close();
                }
                click_manager_->checkEvents(event, sf::Vector2f(1, 1), this);
            }
            clear(sf::Color(240, 240, 240));

            draw(query_);
            draw(message_box_);
            display();
        }
    }

private:

    void alignWindow() {
        size_t x_centre = (sf::VideoMode::getDesktopMode().width - size_.x) / 2;
        size_t y_centre = (sf::VideoMode::getDesktopMode().height - size_.y) / 2;
        setPosition(sf::Vector2i(x_centre, y_centre));
    }

    void queryConstructor(std::string&& query_text) {
        query_.setFont(font_);
        query_.setString(query_text);
        query_.setFillColor(sf::Color::Black);
        query_.setCharacterSize(25);
        alignQuery();
    }

    void alignQuery() {
        sf::FloatRect bounds = query_.getLocalBounds();
        sf::Vector2f query_centre = sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        query_.setOrigin(query_centre);
        sf::Vector2f query_pos = sf::Vector2f(static_cast<float>(size_.x) / 2, static_cast<float>(size_.y) / 3);
        query_.setPosition(query_pos);
    }

    void responseConstructor() {
        std::cout << message_box_.getPosition().x << " " << message_box_.getPosition().y << std::endl;
        sf::FloatRect bounds = message_box_.getLocalBounds();
        sf::Vector2f response_centre = sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        message_box_.setOrigin(response_centre);
        sf::Vector2f response_pos = sf::Vector2f(static_cast<float>(size_.x) / 2, static_cast<float>(size_.y) * 2 / 3);
        message_box_.setPosition(response_pos);
        std::cout << message_box_.getPosition().x << " " << message_box_.getPosition().y << std::endl;
        std::cout << message_box_.getSize().x << " " << message_box_.getSize().y << std::endl;
       // response_pos -= sf::Vector2f(bounds.width / 2, bounds.height / 2);
//        std::cout << message_box_.getPosition().x << " " << message_box_.getPosition().y << std::endl;
//        std::cout << message_box_.getSize().x << " " << message_box_.getSize().y << std::endl;
    }

    const sf::Vector2u size_;
    sf::Font font_;
    sf::Text query_;
    MessageBox message_box_;
    ClickManager* click_manager_;
};


#endif //LEVELGENERATOR_DIALOGWINDOW_H