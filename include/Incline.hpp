#ifndef INCLINE_HPP 
#define INCLINE_HPP 
#include "SFML/Graphics.hpp"

class Incline{
    private:
        sf::CircleShape triangle;
        float static_Coefficient; 
        float kinetic_Coefficient;
        float angle;
    public: 
        Incline(float angle, sf::Vector2f position, sf::Vector2f size){
            triangle.setPointCount(3); 
            triangle.setRadius(50);            
        }; 
        ~Incline(){};
};


#endif 