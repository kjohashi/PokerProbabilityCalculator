//
// Created by Kota Ohashi on 5/26/24.
//

#ifndef POKER_SFMLBACKGROUND_H
#define POKER_SFMLBACKGROUND_H

#include <SFML/Graphics.hpp>

class SFMLBackground : public sf::RectangleShape {
public:
    // Constructors
    SFMLBackground();
    SFMLBackground(float width, float height);

    // Setters
    void setBackground();
    void setBackground(float width, float height);

    // Getters
    float getWidth();
    float getHeight();

private:
    float width = 88, height = 120; // Default width/height
};

#endif //POKER_SFMLBACKGROUND_H
