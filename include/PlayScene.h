#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Meteor.h"
#include "Defender_L.h"
#include "Defender_R.h"
#include "Collisionable.h"
#include "Barrel.h"
#include "Spaceship.h"
#include "BaseScene.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class PlayScene: public BaseScene{
    private:
        sf::RenderWindow w; //sfml
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Music music;
        Defender_L *defender_l;
        Defender_R *defender_r;
        Barrel *barrel;
        Barrel *barrel_l;
        Barrel *barrel_r;
        Spaceship *spaceship;
        Meteor *meteor;

        int vida = 3;
        int score = 0;
        //textos
        sf::Font fuente;
        sf::Text txt;
        sf::Text vidas;

        vector<Object *> objects;

        void init();
        void colisiones_meteor();
        void aumentarScore();

    public:
        PlayScene();
        ~PlayScene();
        void run();
        void add(Object *o);
        bool pause = false;

        void update();
        void draw(sf::RenderWindow &w);

};
#endif // PLAY_SCENE_H
