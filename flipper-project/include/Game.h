#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>


class Game {
    public:
        Game();
        void run();
        void switchScene();
        static getInstance();

    private:
        sf::RenderWindow w;
        void init();
        void update();
        void draw();
        static getInstancePrivate();
        static createPrivate();
};

#endif // GAME_H
