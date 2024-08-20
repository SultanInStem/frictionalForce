#ifndef BLOCK_HPP 
#define BLOCK_HPP 
#include "SFML/Graphics.hpp"

class Block{
    private: 
        float mass; 
        sf::RectangleShape shape; 
    public: 
        Block(int width = 50, int height = 50){
            shape.setSize(sf::Vector2f(width, height));
            shape.setFillColor(sf::Color::Red);
            shape.setPosition(sf::Vector2f(0,0));
        };
        ~Block(){};
        void show(sf::RenderWindow& window){
            window.draw(shape); 
        }
};

#endif 