#ifndef GAMEPLAY_H
#define GAMEPLAY_H


class GamePlay
{
    public:
        GamePlay();
        void update();
        void draw();
        bool state();

    private:
        void init();
};

#endif // GAMEPLAY_H
