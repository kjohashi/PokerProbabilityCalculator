//
// Created by Kota Ohashi on 5/26/24.
//

#include "SFMLBackground.h"

SFMLBackground::SFMLBackground() {
    setBackground();
}

void SFMLBackground::setBackground() {
    // Default width/height, fill color = white
    this->setSize(sf::Vector2f(width, height));
    this->setFillColor(sf::Color(255, 255, 255));

}

void SFMLBackground::setBackground(float width, float height) {
    // Sets size = width and height.
    this->setSize(sf::Vector2f(width, height));
}


float SFMLBackground::getWidth() {
    return width;
}

float SFMLBackground::getHeight() {
    return height;
}

// Draw a green rectangle covering the entire window
sf::RectangleShape greenBackground(sf::Vector2f(window.getSize().x, window.getSize().y));
greenBackground.setFillColor(sf::Color::Green);
window.draw(greenBackground);sf::Font font;

