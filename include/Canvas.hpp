#ifndef CANVAS_HPP 
#define CANVAS_HPP 
#include "SFML/Graphics.hpp"

class Canvas{
    private: 
        sf::RenderWindow window; 
        void update(); 
        void handleEvents(); 
        void render(); 
    public: 
        Canvas(); 
        ~Canvas(); 
        void run(); 

};

#endif