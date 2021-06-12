#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Meteor.h"

class Spaceship: public Object{
    public:
        Spaceship(const sf::Vector2f &pos);
        void update();
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();
        //bool collidesWithMeteor(Meteor *m);
    private:
        sf::Sprite spSpaceship;
        sf::Texture texSpaceship;
};
#endif // SPACESHIP_H
