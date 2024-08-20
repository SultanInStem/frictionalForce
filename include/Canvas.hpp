#ifndef CANVAS_HPP 
#define CANVAS_HPP 
#include "Incline.hpp"
#include "SFML/Graphics.hpp"
class Canvas{
    private: 
        float G = 9.81; 
        sf::RenderWindow window; 
        sf::View view; 
        Incline incline; 
        void update(); 
        void handleEvents(); 
        void render(); 
    public: 
        Canvas(int width = 1080, int height = 920); 
        ~Canvas(); 
        void run(); 

};

#endif