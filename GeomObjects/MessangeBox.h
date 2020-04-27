#ifndef LEVELGENERATOR_MESSANGEBOX_H
#define LEVELGENERATOR_MESSANGEBOX_H

class MessageBox : public sf::Transformable, public sf::Drawable {
public:
    MessageBox(sf::Vector2u pos, size_t max_char_cnt = 50) :
        pos_(pos),
        char_bound_(max_char_cnt),
        text_box_(sf::Vector2f(15 * char_bound_, 20)) {


    }

private:
    sf::Vector2u pos_;
    size_t char_bound_;
    sf::RectangleShape text_box_;
    sf::Font font_;

};

#endif
