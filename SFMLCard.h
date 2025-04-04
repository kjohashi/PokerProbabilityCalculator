#ifndef CS3A_POKEREXAMPLE_SFMLCARD_H
#define CS3A_POKEREXAMPLE_SFMLCARD_H
#include "AnimatedSpriteSheet.h"
#include "CardVariables.h"
#include "SFMLBackground.h"
#include "SFMLSuit.h"
#include "SFMLRank.h"

class SFMLCard : public sf::Drawable {
public:
    // Constructors
    SFMLCard();
    SFMLCard(ranks, suits);
    SFMLCard(ranks, suits, float positionX, float positionY);

    void setCard(ranks, suits, float positionX, float positionY);
    void setRank(ranks, suits);
    void setSuit(suits);
    void setBackground();

    void setPosition(float x, float y);
    float getPositionX();
    float getPositionY();

    float getWidth();
    float getHeight();

    // Function that must be declared/implemented for Card to be considered a child of sf::Drawable
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    SFMLBackground background;
    SFMLRank rank;
    SFMLSuit suit;
};

#endif //MAIN_CPP_SFMLCARD_H