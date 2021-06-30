#include "../include/PlayScene.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "../include/Meteor.h"
using namespace std;

PlayScene::PlayScene()
{
    init();
}

void PlayScene::init(){//inicializacion

    texBackground.loadFromFile("assets/images/background.jpg");
    spBackground.setTexture(texBackground);

    //Font de puntos, en proceso...
    //fontScoreText.loadFromFile("assets/fonts/point");

    //score = 0;
    //scoreText.setFont(fontScoreText);
    //scoreText.setColor(sf::Color(255, 0, 0));
    //scoreText.setCharacterSize(80);
    //scoreText.setPosition(50,50);
    //musica
    music.openFromFile("assets/music/music.ogg");
	music.setLoop(true);
	music.play();

    meteor = new Meteor();
    add(meteor);
    defender_r = new Defender_R(sf::Vector2f(210,390));
    add(defender_r);
    defender_l = new Defender_L(sf::Vector2f(100,390));
    add(defender_l);
    barrel = new Barrel(sf::Vector2f(190,40));
    add(barrel);
    barrel_l = new Barrel(sf::Vector2f(95,100));
    add(barrel_l);
    barrel_r = new Barrel(sf::Vector2f(285,100));
    add(barrel_r);
    spaceship = new Spaceship(sf::Vector2f(165,400));
    add(spaceship);

}
void PlayScene::add(Object *o){
    objects.push_back(o);
}

void PlayScene::run(){// se corre el bucle
    }
void PlayScene::colisiones_meteor(){//esto se encuentra funcional pero me gustaría optimizarlo

    sf::FloatRect meteorRect = meteor-> getSprite().getGlobalBounds();
    sf::FloatRect defender_lRect = defender_l-> getSprite().getGlobalBounds();
    sf::FloatRect defender_rRect = defender_r-> getSprite().getGlobalBounds();
    sf::FloatRect barrelRect = barrel-> getSprite().getGlobalBounds();
    sf::FloatRect barrel_lRect = barrel_l-> getSprite().getGlobalBounds();
    sf::FloatRect barrel_rRect = barrel_r-> getSprite().getGlobalBounds();
    sf::FloatRect spaceshipRect = spaceship-> getSprite().getGlobalBounds();
    bool crash_r = meteorRect.intersects(defender_rRect);
    bool crash_l = meteorRect.intersects(defender_lRect);
    bool lost = meteorRect.intersects(spaceshipRect);
    bool points = meteorRect.intersects(barrelRect);
    bool barrel_l = meteorRect.intersects(barrel_lRect);
    bool barrel_r = meteorRect.intersects(barrel_rRect);
    //si choca con defender r y defender l
    if(crash_l || crash_r || barrel_l || barrel_r){
        //cambiar el rumbo del meteorito para el otro lado con velocidad contraria
        meteor-> velMeteor.x *= -1;
        meteor-> velMeteor.y *= -1.001;
    }
    if(lost){w.close();}

    if(points){//cuando toca el barril los puntos suben más rapido pero también la velocidad
        //score += 10;
        meteor-> velMeteor.x *= -1.2;
        meteor-> velMeteor.y *= -1.2;
    }

}
void PlayScene::update(){
    if (!pause) BaseScene::update();

    colisiones_meteor();
    /*score +=1;
    scoreText.setString("SCORE :");*/
}


void PlayScene::draw(sf::RenderWindow &w){
    w.clear(sf::Color::Black); //limpia la pantalla
    w.draw(spBackground);
    BaseScene::draw(w);
    w.display();
}

PlayScene::~PlayScene(){}
