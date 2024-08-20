#include "Canvas.hpp"
#include "Block.hpp"
#include "Incline.hpp"
Canvas::Canvas(int width, int height) : incline(30), block(50,50){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  
    window.create(sf::VideoMode(width,height), "Friction Force", sf::Style::Titlebar | sf::Style::Close, settings); 
    window.setFramerateLimit(90);
}; 
Canvas::~Canvas(){}

void Canvas::run(){
    while(window.isOpen()){
        update(); 
        handleEvents(); 
        render(); 
    }
}
void Canvas::handleEvents(){
    sf::Event event; 
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}
void Canvas::update(){

};
void Canvas::render(){
    window.clear(sf::Color::Black);

    window.display(); 
};