#include "Canvas.hpp"
#include "Incline.hpp"
Canvas::Canvas(int width, int height) : incline(60, 300){
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 15;  
    window.create(sf::VideoMode(width,height), "Friction Force", sf::Style::Titlebar | sf::Style::Close, settings); 
    window.setFramerateLimit(90);
    view.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view.setCenter(sf::Vector2f(0,0));
    window.setView(view); 
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
    // check if gravitational force can overcome static friction 
    float force = incline.mass * G * sin(incline.angle * (M_PI / 180.f));
    float staticFriction = incline.static_Coefficient * incline.mass * G; 
    float kineticFriction = incline.kinetic_Coefficient * incline.mass * G; 
    if(abs(force) < abs(staticFriction)) return; 
    float netForce = force - kineticFriction; 
    float acc = netForce / incline.mass; 

    // YOU LEFT HERE 





};
void Canvas::render(){
    window.clear(sf::Color::Black);
    incline.show(window); 
    window.display(); 
};