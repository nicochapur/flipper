#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Meteor.h"
#include "Defender_L.h"
#include "Defender_R.h"
#include "Barrel.h"
#include "Spaceship.h"
#include <vector>
#include <string>

using namespace std;

class Game{
    private:
        sf::RenderWindow w; //sfml
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Music music;
        //float score;
        //sf::Text scoreText;
        //sf::Font fontScoreText;
        Defender_L *defender_l;
        Defender_R *defender_r;
        Barrel *barrel;
        Barrel *barrel_l;
        Barrel *barrel_r;
        Spaceship *spaceship;
        Meteor *meteor;

        vector<Object *> objects;

        void init();
        void update();
        void draw();

    public:
        Game();
        ~Game();
        void run();
        void colisiones_meteor();
        void add(Object *o);
        bool pause = false;

};
#endif // GAME_H
