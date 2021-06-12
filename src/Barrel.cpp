#include "../include/Barrel.h"

#include <SFML/Window/Keyboard.hpp>

Barrel::Barrel(const sf::Vector2f &pos){
    texbarrel.loadFromFile("assets/images/barrel.png");
    spbarrel.setTexture(texbarrel);
    spbarrel.setPosition(pos);
}

void Barrel::update(){}

void Barrel::draw(sf::RenderWindow &w){
    w.draw(spbarrel);
}

sf::Sprite &Barrel::getSprite(){
    return spbarrel;}

/*bool Barrel::collidesWithMeteor(Meteor *m){
    sf::FloatRect barrelRect = getSprite().getGlobalBounds();
    sf::FloatRect meteorRect = m-> getSprite().getGlobalBounds();
    return barrelRect.intersects(meteorRect);
}*/

