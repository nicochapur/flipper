#ifndef GLOBAL_H
#define GLOBAL_H


class Global
{
    public:
        Global();
        void setHighScore(const int);
        void setLastScore(const int);
        int getHighScore();
        int getLastScore();
    private:
        int highScore;
        int lastScore;
};



#endif // GLOBAL_H
