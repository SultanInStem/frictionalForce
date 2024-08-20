#ifndef INCLINE_HPP 
#define INCLINE_HPP 
#include "SFML/Graphics.hpp"
#include <iostream>
class Incline{
    private:
        sf::ConvexShape triangle;
        float static_Coefficient; 
        float kinetic_Coefficient;
        float angle;
    public: 
        Incline(float angle, float base){
            // tan(angle) = height / base
            // height = base * tan(angle)
            this->angle = angle * (M_PI / 180);
            sf::Vector2f point1(-base / 2,0); 
            sf::Vector2f point2(base / 2, 0); 
            sf::Vector2f point3(base / 2, -base * tan(this->angle));
            sf::Vector2f centroid(
                (point1.x + point2.x + point3.x) / 3.f, 
                (point1.y + point2.y + point3.y) / 3.f
            );
            sf::Vector2f triangleOrigin(0,0);
            sf::Vector2f offset = triangleOrigin -centroid;
            triangle.setPointCount(3); 
            triangle.setPoint(0, point1 + offset); 
            triangle.setPoint(1, point2 + offset); 
            triangle.setPoint(2, point3 + offset); 
            triangle.setFillColor(sf::Color::Green);
        }; 
        ~Incline(){};
        void show(sf::RenderWindow& window){
            window.draw(triangle);
        }
};


#endif 