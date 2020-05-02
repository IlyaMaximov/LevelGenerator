#ifndef LEVELGENERATOR_DIALOGWINDOW_H
#define LEVELGENERATOR_DIALOGWINDOW_H

#include "SFML/Graphics.hpp"
#include "../Managers/ClickManager.h"
#include <iostream>


class DialogWindow : public sf::RenderWindow {
public:
    explicit DialogWindow(std::string&& message, std::string* user_response, ClickManager* click_manager = nullptr);

    ~DialogWindow() override;

    void EnterPressed(MessageBox*);
    void run();

private:

    void alignWindow();
    void queryConstructor(std::string&& query_text);
    void alignQuery();
    void alignResponse();

    bool close_window_ = false;
    bool init_click_manager_ = false;

    const sf::Vector2u size_;
    sf::Font font_;
    sf::Text query_;
    MessageBox message_box_;
    std::string* user_response_;
    ClickManager* click_manager_;
};


#endif //LEVELGENERATOR_DIALOGWINDOW_H