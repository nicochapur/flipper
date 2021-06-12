#ifndef DEFENDER_L_H
#define DEFENDER_L_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Meteor.h"
#include "Defender_L.h"

class Defender_L: public Object{
    public:
        Defender_L(const sf::Vector2f &pos);
        void update() override;
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();
        //bool collidesWithMeteor(Meteor *m);
    private:
        sf::Sprite spDefender_L;
        sf::Texture texDefender_L;
        float rotacion = 0 ;
};

#endif // DEFENDER_L_H
