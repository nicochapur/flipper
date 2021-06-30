#include "EndGame.h"

EndGame::EndGame()
{
    init();
}

void EndGame::init(){//inicializacion
    //ventana
    w.create(sf::VideoMode(400,500), "SPACESHIP");

    // actualizaciones por segundo
    w.setFramerateLimit(60);

    //fondo
    texBackground.loadFromFile("assets/images/background.jpg"); /// TO DO modificar fondo sin lineas
    spBackground.setTexture(texBackground);

    //musica
//    music.openFromFile("assets/music/music.ogg");
//	music.setLoop(true);
//	music.play();
}

void EndGame::run(){// se corre el bucle
    while(w.isOpen()){

        sf::Event o;
        while(w.pollEvent(o)){
            if(o.type == sf::Event::Closed)
                w.close();//trabaja con una cola de eventos
        }

        update();//actualiza

        draw();//dibuja
}}

void EndGame::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){//si se aprieta esc se cierra
        // comienza el juego
        // switchScene('Game');
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)){//si se aprieta esc se cierra
        w.close();
    }
}

void EndGame::draw(){
    w.clear(sf::Color::Black); //limpia la pantalla
    w.draw(spBackground);

    w.display();
}
