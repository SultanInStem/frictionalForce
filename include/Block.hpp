#ifndef BLOCK_HPP 
#define BLOCK_HPP 
#include "SFML/Graphics.hpp"

class Block{
    private: 
        float mass; 
        sf::RectangleShape shape; 
    public: 
        Block(int width, int height){
            shape.setSize(sf::Vector2f(width, height));
            shape.setFillColor(sf::Color::Red);
        };
        ~Block(){};
};


#endif 