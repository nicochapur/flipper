 #include "BaseScene.h"

BaseScene::BaseScene(){

}

void BaseScene::update() {
    for(auto o: objects){
        o-> update();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){//si se aprieta esc se cierra
//        w.close();
    }

    // elimina los actores
//    for(auto d: to_delete){
//        auto it = find(objects.begin(), Objects.end(), d);
//        if(it!= objects.end()){
//            objects.erase(it)
//        }
//    }
//    to_delete.clear();
}

void BaseScene::draw(sf::RenderWindow &w){
    for(auto o: objects){
        o-> draw(w);
    }
}

void BaseScene::add(Object *o){
    objects.push_back(o);
}

//void BaseScene::remove(Object *o){
//    to_delete.push_back(o);
//}
