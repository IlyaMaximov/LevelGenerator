#ifndef LEVELGENERATOR_WINDOWOBJ_H
#define LEVELGENERATOR_WINDOWOBJ_H

#include <SFML/Graphics.hpp>
#include <iostream>

class WindowObj : public sf::Drawable, public sf::Transformable {
public:
    virtual void AcceptEvent(sf::Event&, const sf::Vector2f &pos) {};
};

#endif //LEVELGENERATOR_WINDOWOBJ_H
