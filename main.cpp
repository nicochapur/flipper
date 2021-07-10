#include<stdlib.h>
#include<time.h>
#include "BaseScene.h"
#include "Menu.h"
#include "Game.h"
#include "EndGame.h"

int main ( int argc, char** argv ){
    BaseScene *scene = new EndGame();
    Game &g = Game::create(sf::VideoMode(400, 500), scene, "SPACESHIP");

    g.run();

    return 0;

}
