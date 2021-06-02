#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

Game::Game(){
    init();
}

void Game::init(){
    w.create(sf::VideoMode(640, 400), "SFML");
}

void Game::run(){
    while(w.isOpen()){
        // necesario para quitar los eventos de la cola de la ventana
        sf::Event e;
        while(w.pollEvent(e)){
            if(e.type == sf::Event::Closed) w.close();
        }

        update();

        draw();
    }
}

void Game::update(){
}

void Game::draw(){
    w.clear(sf::Color::Black);

    w.display();
}
