#include "../include/Meteor.h"


Meteor::Meteor(){
    /*Aquí cargamos la imagen del meteorito e indicamos su posicion*/
    texMeteor.loadFromFile("assets/images/meteor.png");
    spMeteor.setTexture(texMeteor);
    spMeteor.setOrigin(spMeteor.getLocalBounds().width/2.0f, spMeteor.getLocalBounds().height/2.0f);
    spMeteor.setScale(0.25,0.25);
    srand(time(0)); //que se mueva random
    spMeteor.setPosition(rand()%200, 200);
    velMeteor.x = 2+rand()%3;
    velMeteor.y = 2+rand()%3;
}

void Meteor::update(){
    /* Aquí iniciamos en un lugar random el meteorito y luego lo mantenemos
    en un rango para que no se escape de la pantalla.*/
    spMeteor.move(velMeteor);

    sf::Vector2f meteorPos = spMeteor.getPosition();
    if(meteorPos.x < 0){
        spMeteor.setPosition(meteorPos.x, rand()%381);
        velMeteor.x *= -1;
    }
    if(meteorPos.x > 388 ){
        spMeteor.setPosition(meteorPos.x, rand()%381);
        velMeteor.x *= -1;
    }
    if(meteorPos.y < 0){
        spMeteor.setPosition(rand()%381,meteorPos.y);
        velMeteor.y *= -1;
    }
    if(meteorPos.y > 381){
        spMeteor.setPosition(rand()%381,meteorPos.y);
        velMeteor.y *= -1;
    }
    spMeteor.setPosition(meteorPos);

}

void Meteor::draw(sf::RenderWindow &w){
    w.draw(spMeteor);
}

sf::Sprite &Meteor::getSprite(){
    return spMeteor;}
/*
bool Meteor::collidesWithDefender_L(Defender_L *l){
    sf::FloatRect meteorRect = getSprite().getGlobalBounds();
    sf::FloatRect defender_lRect = defender_l-> getSprite().getGlobalBounds();
    return meteorRect.intersects(defender_lRect);
}

bool Meteor::collidesWithDefender_R(Defender_R *defender_r){
    sf::FloatRect meteorRect = getSprite().getGlobalBounds();
    sf::FloatRect defender_RRect = defender_r-> getSprite().getGlobalBounds();
    return meteorRect.intersects(defender_rRect);
}

bool Meteor::collidesWithBarrel(Barrel *barrel){
    sf::FloatRect meteorRect = getSprite().getGlobalBounds();
    sf::FloatRect barrelRect = barrel-> getSprite().getGlobalBounds();
    return meteorRect.intersects(barrelRect);
}

bool Meteor::collidesWithSpaceship(Spaceship *spaceship){
    sf::FloatRect meteorRect = getSprite().getGlobalBounds();
    sf::FloatRect spaceshipRect = spaceship-> getSprite().getGlobalBounds();
    return meteorRect.intersects(spaceshipRect);
}
*/
