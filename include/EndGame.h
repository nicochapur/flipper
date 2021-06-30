#ifndef ENDGAME_H
#define ENDGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

using namespace std;

class EndGame
{
    private:
        sf::RenderWindow w; //sfml
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Music music;

        void init();
        void update();
        void draw();

    public:
        EndGame();
        void run();
};

#endif // ENDGAME_H
