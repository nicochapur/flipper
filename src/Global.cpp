#include <iostream>
using namespace std;
#include "Global.h"

Global::Global(){
    cout << "constructor";
    highScore = 0;
    lastScore = 0;
}

void Global::setHighScore(int h){
    if (h > 0) highScore=h;
}
void Global::setLastScore(int l){
    if (l > 0) lastScore=l;
}
int Global::getHighScore(){
    return highScore;
}
int Global::getLastScore(){
    return lastScore;
}
