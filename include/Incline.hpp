#ifndef INCLINE_HPP 
#define INCLINE_HPP 

#include "SFML/Graphics.hpp"
#include <iostream>
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
            sf::Vector2f point1(-base / 2,0); 
            sf::Vector2f point2(base / 2, 0); 
            sf::Vector2f point3(base / 2, -base * tan(angle * (M_PI / 180)));
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


            blockShape.setSize(sf::Vector2f(50,50));
            blockShape.setOrigin(sf::Vector2f(blockShape.getSize().x / 2.f, blockShape.getSize().y / 2.f));
            blockShape.setFillColor(sf::Color::Red);
            blockShape.setRotation(angle);
            blockShape.setPosition(sf::Vector2f(0, -200));

        }; 
        ~Incline(){};
        void show(sf::RenderWindow& window){
            window.draw(triangle);
            window.draw(blockShape);
        }
        
};


#endif 