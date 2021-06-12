#include "../include/Spaceship.h"
#include <SFML/Window/Keyboard.hpp>
Spaceship::Spaceship(const sf::Vector2f &pos){
    texSpaceship.loadFromFile("assets/images/spaceship.png");
    spSpaceship.setTexture(texSpaceship);
    spSpaceship.setPosition(pos);
    spSpaceship.setScale(0.2,0.2);
}

void Spaceship::update(){}

void Spaceship::draw(sf::RenderWindow &w){
    w.draw(spSpaceship);
}

sf::Sprite &Spaceship::getSprite(){
    return spSpaceship;}

/*bool Spaceship::collidesWithMeteor(Meteor *m){
    sf::FloatRect spaceshipRect = getSprite().getGlobalBounds();
    sf::FloatRect meteorRect = m-> getSprite().getGlobalBounds();
    return spaceshipRect.intersects(meteorRect);
}*/
