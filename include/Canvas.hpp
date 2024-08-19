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
        Canvas(int width = 1080, int height = 920); 
        ~Canvas(); 
        void run(); 

};

#endif