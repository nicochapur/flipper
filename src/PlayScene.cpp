#include "../include/PlayScene.h"
#include "Global.h"
#include "Game.h"
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

    //texto
    fuente.loadFromFile("assets/fonts/font.ttf");
    txt.setFont(fuente);
    txt.setString("score "+ to_string(score));
    txt.setFillColor(sf::Color::White);
    txt.setPosition(25,420);
    txt.setScale(0.5,0.5);

    //texto de vidas

    vidas.setFont(fuente);
    vidas.setString("vidas " + to_string(vida));
    vidas.setFillColor(sf::Color::White);
    vidas.setPosition(330,420);
    vidas.setScale(0.5,0.5);

    //musica
    /*music.openFromFile("assets/music/music.ogg");
    music.setLoop(true);
    music.play();*/


    defender_r = new Defender_R(sf::Vector2f(210,390));
    BaseScene::add(defender_r);
    defender_l = new Defender_L(sf::Vector2f(100,390));
    BaseScene::add(defender_l);
    barrel = new Barrel(sf::Vector2f(190,40));
    BaseScene::add(barrel);
    barrel_l = new Barrel(sf::Vector2f(95,100));
    BaseScene::add(barrel_l);
    barrel_r = new Barrel(sf::Vector2f(285,100));
    BaseScene::add(barrel_r);
    spaceship = new Spaceship(sf::Vector2f(165,400));
    BaseScene::add(spaceship);
    meteor = new Meteor();
    BaseScene::add(meteor);
}

void PlayScene::aumentarScore()
{
    score +=1;
    txt.setString("score "+ to_string(score));
}



void PlayScene::colisiones_meteor()
{
    if(meteor->isCollision(*defender_l))
    {
        aumentarScore();
        meteor->moveMeteor(*defender_l);
    }
    if(meteor->isCollision(*defender_r))
    {
        aumentarScore();
        meteor->moveMeteor(*defender_r);
    }
    if(meteor->isCollision(*spaceship)){
        vida--;
        if(vida==0){
            cout<<Global::getHighScore();
            if(score > Global::getHighScore()){
                Global::setHighScore(score);
            }
            Global::setLastScore(score);
            int o = Global::getHighScore();
            cout<<o;
            cout<<"score";
            //w.close();
            Game::getInstance().switchScene(new EndGame());
        }
        vidas.setString("vidas " + to_string(vida));
        meteor->moveMeteor(*spaceship);
    }
    if(meteor->isCollision(*barrel_l)){
        aumentarScore();
        meteor->moveMeteor(*barrel_l);
    }
    if(meteor->isCollision(*barrel_r)){
        aumentarScore();
        meteor->moveMeteor(*barrel_r);
    }
    if(meteor->isCollision(*barrel)){
        aumentarScore();
        meteor->moveMeteor(*barrel);
    }
}
void PlayScene::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        if(pause == true){
            pause = false;
        }
        else{pause = true;}
        }
    if(!pause) BaseScene::update();
        colisiones_meteor();
}

void PlayScene::draw(sf::RenderWindow &w)
{
    w.draw(spBackground);
    BaseScene::draw(w);
    w.draw(txt);
    w.draw(vidas);
}
