#ifndef BARREL_H
#define BARREL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../include/Object.h"
#include "../include/Meteor.h"

class Barrel: public Object{
    public:
        Barrel(const sf::Vector2f &pos);
        void update();
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();
        //bool collidesWithMeteor(Meteor *m);
    private:
        sf::Texture texbarrel;
        sf::Sprite spbarrel;

};

#endif // BARREL_H
