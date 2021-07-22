#include "Menu.h"
#include "Global.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "Game.h"
#include "PlayScene.h"

using namespace std;
Menu::Menu(){
    // LOAD BACKGROUND IMAGE
    texBackground.loadFromFile("assets/images/menu-background.jpg");
    spBackground.setTexture(texBackground);
    spBackground.setScale(0.5, 0.5);

    // LOAD FONT
    if(!textFont.loadFromFile("assets/fonts/menu-font.ttf")){
        cout << "Error loading font" << endl;
    };
    // GAME TITLE
    titleText.setFont(textFont);
    titleText.setColor(sf::Color::White);
    titleText.setString("Flipper");
    titleText.setCharacterSize(48);
    titleText.setPosition(sf::Vector2f((400-titleText.getGlobalBounds().width)/2.0, 50));

    // PLAY
    playText.setFont(textFont);
    playText.setColor(sf::Color::White);
    playText.setString("Press TAB to start");
    playText.setCharacterSize(16);
    playText.setPosition(sf::Vector2f((400-playText.getGlobalBounds().width)/2.0, 250));

    // EXIT OPTION
    exitText.setFont(textFont);
    exitText.setColor(sf::Color::Yellow);
    exitText.setString("[backspace] - Exit");
    exitText.setCharacterSize(10);
    exitText.setPosition(230, 480);

    //musica
//    music.openFromFile("assets/music/music.ogg");
//	music.setLoop(true);
//	music.play();
}

void Menu::update(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        Game::getInstance().switchScene(new PlayScene());
    }
}

void Menu::draw(sf::RenderWindow &w){
    w.draw(spBackground);
    w.draw(titleText);
    w.draw(playText);
    w.draw(exitText);
}
