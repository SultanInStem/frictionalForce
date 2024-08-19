#ifndef INCLINE_HPP 
#define INCLINE_HPP 
#include "SFML/Graphics.hpp"


class Incline{
    private:
        sf::CircleShape triangle;
    public: 
        Incline(float angle, sf::Vector2f position, sf::Vector2f size){
            triangle.setPointCount(3); 
            triangle.setRadius(50);            
        }; 
        ~Incline(){};
};


#endif 