#ifndef INCLINE_HPP 
#define INCLINE_HPP 
#include "SFML/Graphics.hpp"

class Incline{
    private:
        sf::ConvexShape triangle;
        float static_Coefficient; 
        float kinetic_Coefficient;
        float angle;
    public: 
        Incline(float angle){
            triangle.setPointCount(3); 
            triangle.setPoint(0, sf::Vector2f(100,100)); 
            triangle.setPoint(1, sf::Vector2f(200,100)); 
            triangle.setPoint(2, sf::Vector2f(200,200)); 
            triangle.setFillColor(sf::Color::Green);
        }; 
        ~Incline(){};
        void show(sf::RenderWindow& window){
            window.draw(triangle);
        }
};


#endif 