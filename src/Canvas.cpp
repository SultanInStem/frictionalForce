#include "Canvas.hpp"

Canvas::Canvas(int width, int height){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  
    window.create(sf::VideoMode(width,height), "Friction Force", sf::Style::Titlebar | sf::Style::Close, settings); 
}; 
Canvas::~Canvas(){}

void Canvas::run(){

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

}
void Canvas::render(){}