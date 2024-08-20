#ifndef INCLINE_HPP 
#define INCLINE_HPP 
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
class Incline{
    private:
        sf::RectangleShape blockShape;
        sf::ConvexShape triangle;
        float static_Coefficient; 
        float kinetic_Coefficient;
        float angle;
        float mass; 

    public: 
        Incline(float angle, float base){
            // tan(angle) = height / base
            // height = base * tan(angle)
            this->angle = angle;
            float angleRad = angle * (M_PI / 180.f);
            float height = -base * tan(angleRad); 
            sf::Vector2f point1(-base / 2,0); 
            sf::Vector2f point2(base / 2, 0); 
            sf::Vector2f point3(base / 2, height);
            sf::Vector2f centroid(
                (point1.x + point2.x + point3.x) / 3.f, 
                (point1.y + point2.y + point3.y) / 3.f
            );
            sf::Vector2f triangleOrigin(0,0);
            sf::Vector2f offset = triangleOrigin -centroid;
            point1 += offset; 
            point2 += offset; 
            point3 += offset;
            triangle.setPointCount(3); 
            triangle.setPoint(0, point1); 
            triangle.setPoint(1, point2); 
            triangle.setPoint(2, point3); 
            triangle.setFillColor(sf::Color::Green);
            float m = (point1.y - point3.y) / (point1.x - point3.x);
            float b = point1.y - (m * point1.x);
            // y = mx + b  


            blockShape.setSize(sf::Vector2f(50.f,50.f));
            blockShape.setOrigin(blockShape.getSize().x / 2.f, blockShape.getSize().y);
            blockShape.setPosition(sf::Vector2f((point3.y - b) / m, point3.y));
            blockShape.setFillColor(sf::Color::Red);
            blockShape.setRotation(-angle); 

            

        }; 
        ~Incline(){};
        void show(sf::RenderWindow& window){
            window.draw(triangle);
            window.draw(blockShape);
        }
        
};


#endif 