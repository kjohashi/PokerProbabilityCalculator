#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "AnimatedSpriteSheet.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include "Deck.h"
#include "SFMLCard.h"
using namespace std;
int main() {
    srand(time(nullptr));
    PokerScore total;
    for(int i=0;i<1000;i++) {
    Deck deck;
    deck.shuffle();

    CardHand player1,player2,player3,player4,player5;
    for (int j = 0; j < 5; j++) {
        player1.addCard(deck.dealCard());
        player2.addCard(deck.dealCard());
        player3.addCard(deck.dealCard());
        player4.addCard(deck.dealCard());
        player5.addCard(deck.dealCard());
    }

    total+= CardHandScorer::scorePokerHand(player1);
    }
    std::cout << total;

    //Window width and height
    sf::RenderWindow window({1920,1080,32},"POKER");
    window.setFramerateLimit(60);

    //Animated Sprite Sheet initialization
    AnimatedSpriteSheet sprite("P0K3R.png", 4, 13);
    SFMLCard aceClubs(ACE, CLUBS);
    SFMLCard twoClubs(TWO, CLUBS);
    SFMLCard threeClubs(THREE, CLUBS);
    SFMLCard fourClubs(FOUR, CLUBS);
    SFMLCard fiveClubs(FIVE, CLUBS);
    SFMLCard sixClubs(SIX, CLUBS);
    SFMLCard sevenClubs(SEVEN, CLUBS);
    SFMLCard eightClubs(EIGHT, CLUBS);
    SFMLCard nineClubs(NINE, CLUBS);
    SFMLCard tenClubs(TEN, CLUBS);
    SFMLCard jackClubs(JACK, CLUBS);
    SFMLCard queenClubs(QUEEN, CLUBS);
    SFMLCard kingClubs(KING, CLUBS);
    SFMLCard aceDiamonds(ACE, DIAMONDS);
    SFMLCard twoDiamonds(TWO, DIAMONDS);
    SFMLCard threeDiamonds(THREE, DIAMONDS);
    SFMLCard fourDiamonds(FOUR, DIAMONDS);
    SFMLCard fiveDiamonds(FIVE, DIAMONDS);
    SFMLCard sixDiamonds(SIX, DIAMONDS);
    SFMLCard sevenDiamonds(SEVEN, DIAMONDS);
    SFMLCard eightDiamonds(EIGHT, DIAMONDS);
    SFMLCard nineDiamonds(NINE, DIAMONDS);
    SFMLCard tenDiamonds(TEN, DIAMONDS);
    SFMLCard jackDiamonds(JACK, DIAMONDS);
    SFMLCard queenDiamonds(QUEEN, DIAMONDS);
    SFMLCard kingDiamonds(KING, DIAMONDS);
    SFMLCard aceHearts(ACE, HEARTS);
    SFMLCard twoHearts(TWO, HEARTS);
    SFMLCard threeHearts(THREE, HEARTS);
    SFMLCard fourHearts(FOUR, HEARTS);
    SFMLCard fiveHearts(FIVE, HEARTS);
    SFMLCard sixHearts(SIX, HEARTS);
    SFMLCard sevenHearts(SEVEN, HEARTS);
    SFMLCard eightHearts(EIGHT, HEARTS);
    SFMLCard nineHearts(NINE, HEARTS);
    SFMLCard tenHearts(TEN, HEARTS);
    SFMLCard jackHearts(JACK, HEARTS);
    SFMLCard queenHearts(QUEEN, HEARTS);
    SFMLCard kingHearts(KING, HEARTS);
    SFMLCard aceSpades(ACE, SPADES);
    SFMLCard twoSpades(TWO, SPADES);
    SFMLCard threeSpades(THREE, SPADES);
    SFMLCard fourSpades(FOUR, SPADES);
    SFMLCard fiveSpades(FIVE, SPADES);
    SFMLCard sixSpades(SIX, SPADES);
    SFMLCard sevenSpades(SEVEN, SPADES);
    SFMLCard eightSpades(EIGHT, SPADES);
    SFMLCard nineSpades(NINE, SPADES);
    SFMLCard tenSpades(TEN, SPADES);
    SFMLCard jackSpades(JACK, SPADES);
    SFMLCard queenSpades(QUEEN, SPADES);
    SFMLCard kingSpades(KING, SPADES);


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                window.close();
        }
        window.clear();

        // Draw a green rectangle covering the entire window
        sf::RectangleShape greenBackground(sf::Vector2f(window.getSize().x, window.getSize().y));
        greenBackground.setFillColor(sf::Color::Green);
        window.draw(greenBackground);sf::Font font;

        //test drawings
        window.draw(aceHearts);
        window.draw(twoHearts);
        window.draw(threeHearts);
        window.draw(fourHearts);
        window.draw(fiveHearts);

        window.display();
    }
return 0;
}
