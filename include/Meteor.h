#ifndef METEOR_H
#define METEOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <time.h>
#include "Object.h"
#include "Defender_L.h"
#include "Defender_R.h"
#include "Barrel.h"
#include "Spaceship.h"
#include "Meteor.h"


class Meteor: public Object{
    public:
        Meteor();
        void update() override;
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();
        sf::Vector2f velMeteor;

        //bool collidesWithDefender_L(Defender_L *l);
        //bool collidesWithDefender_R(Defender_R *r);
        //bool collidesWithBarrel(Barrel *b);
        //bool collidesWithSpaceship(Spaceship *s);

    private:
        sf::Sprite spMeteor;
        sf::Texture texMeteor;

};

#endif // METEOR_H
