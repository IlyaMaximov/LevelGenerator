#include "LevelGenerator.h"

LevelGenerator::LevelGenerator(const std::vector<TextureName> &palette_landscapes, TextureManager *texture_manager,
                               const sf::VideoMode &window, ClickManager* click_manager) :
    sf::RenderWindow(window,"Level Generator",sf::Style::Default,sf::ContextSettings(0, 0, 8)),
    size_(this->getSize()),
    texture_manager_(texture_manager),
    space_manager_(window.width, window.height),
    init_click_manager_(click_manager == nullptr),
    click_manager_(init_click_manager_ ? new ClickManager() : click_manager),
    map_(space_manager_.getPos(GeomObj::Map), sf::Vector2u(32, 32), space_manager_.getSize(GeomObj::Map).x / 32,
         space_manager_.getSize(GeomObj::Map).y / 32,texture_manager_),
    minimap_(space_manager_.getPos(GeomObj::Minimap), space_manager_.getSize(GeomObj::Minimap), &map_),
    palette_(space_manager_.getPos(GeomObj::Palette), space_manager_.getSize(GeomObj::Palette),
             texture_manager_, click_manager_, this, palette_landscapes) {

        sizeCheck();
        alignWindow();
        sf::Color button_color = sf::Color(135, 206, 250);
        Button* save_button = new SaveButton(space_manager_.getPos(GeomObj::SaveButton),
                                             space_manager_.getSize(GeomObj::SaveButton),
                                             &map_, button_color);

        Button* open_button = new OpenButton(space_manager_.getPos(GeomObj::OpenButton),
                                             space_manager_.getSize(GeomObj::OpenButton),
                                             &map_, button_color);

        Button* clear_button = new ClearButton(space_manager_.getPos(GeomObj::RunButton),
                                               space_manager_.getSize(GeomObj::RunButton),
                                               &map_, button_color);

        service_buttons_ = {save_button, open_button, clear_button};

        click_manager_->addMap(&map_, this);
        for (auto& button : service_buttons_) {
            click_manager_->addButton(button, this);
        }
}

void LevelGenerator::alignWindow() {
    size_t x_centre = (static_cast<float>(sf::VideoMode::getDesktopMode().width) - size_.x) / 2;
    size_t y_centre = (static_cast<float>(sf::VideoMode::getDesktopMode().height) - size_.y) / 2;
    setPosition(sf::Vector2i(x_centre, y_centre));
}

void LevelGenerator::sizeCheck() const {
    if (size_.x < 650 || size_.y < 430) {
        throw std::invalid_argument("Minimum map size is 650x430");
    }
}


void LevelGenerator::run()  {
    while (isOpen()) {
        sf::Event event{};
        while (pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                close();
            sf::Vector2f scale = {getSize().x / size_.x, getSize().y / size_.y};
            click_manager_->checkEvents(event, scale, this);
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
