#ifndef DEFENDER_R_H
#define DEFENDER_R_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Meteor.h"
#include "Defender_R.h"

class Defender_R: public Object{
    public:
        Defender_R(const sf::Vector2f &pos);
        void update() override;
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();


        //bool collidesWithMeteor(Meteor *m);
    private:
        sf::Sprite spDefender_R;
        sf::Texture texDefender_R;
        float rotacion = 0;
        const float DEFR_VEL = 5;
};

#endif // DEFENDER_R_H
