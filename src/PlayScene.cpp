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



void PlayScene::colisiones_meteor() //esto se encuentra funcional pero me gustaría optimizarlo
{
    if(meteor->isCollision(*defender_l))
    {
        //Si colisiona con estos elementos la velocidad aumenta levemente, también se sumarán puntos.
        aumentarScore();
        meteor-> velMeteor.x *= -1,2;
        meteor-> velMeteor.y *= -1,2;
    }
    if(meteor->isCollision(*defender_r))
    {
        //Si colisiona con estos elementos la velocidad aumenta levemente, también se sumarán puntos.
        aumentarScore();
        meteor-> velMeteor.x *= -1,2;
        meteor-> velMeteor.y *= -1,2;
    }
    if(meteor->isCollision(*spaceship)){
        vida--;
        vidas.setString("vidas " +to_string(vida));
        if(vida==0){
            if(score> Global::highScore){
                Global::highScore = score;
            }
            Global::lastScore = score;
            cout<<"ESTA ES LA PARTE DE COLISIONES";
            cout<<Global::highScore << endl;
            cout<<score;
            w.close();
            //Game::getInstance().switchScene(new EndGame());
        }
    }
    //Si colisiona con el barril de arriba la velocidad aumenta y también se suman puntos.
    if((meteor->isCollision(*barrel_l))||(meteor->isCollision(*barrel_r)))
    {
        aumentarScore();
        meteor-> velMeteor.x *= -1;
        meteor-> velMeteor.y *= -1;
    }
    if(meteor->isCollision(*barrel))
    {
        aumentarScore();
        meteor-> velMeteor.x *= -1;
        meteor-> velMeteor.y *= -1;
    }
}
void PlayScene::update(){
    if(!pause) BaseScene::update();
        colisiones_meteor();
    /*score +=1;
    scoreText.setString("SCORE :");*/
}

void PlayScene::draw(sf::RenderWindow &w)
{
    //w.clear(sf::Color::Black); //limpia la pantalla
    w.draw(spBackground);
    BaseScene::draw(w);
    w.draw(txt);
    w.draw(vidas);
    //w.display();
}

PlayScene::~PlayScene() {}
