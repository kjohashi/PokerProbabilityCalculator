//
// Created by Kota Ohashi on 5/26/24.
//
#ifndef POKER_SFMLRANK_H
#define POKER_SFMLRANK_H
#include "SFMLRank.h"
#include "SFMLSuit.h"

SFMLRank::SFMLRank() {

}

SFMLRank::SFMLRank(enum rank, enum suit) {
    setRank(rank, suit);
}

void SFMLRank::setRank(enum rank, enum suit) {

    // Convert faceValue to value in Hoyle Playing Cards font
    // (in that font, J (Jack) = "a", Q (Queen) = "s", K (King) = "d", etc.)
    std::string convertedFaceValue = hoylePlayingCardFontKey(rank);

    // Load font from file
    if (!font.loadFromFile("hoyle playing cards.ttf"))
        exit(2);

    // Give face value (upper left of card) the following characteristics:
    // Text = convertedFaceValue, font = hoyle playing cards, char size =
    rankUpper = sf::Text(convertedFaceValue, font, 28);

    // If suit = hearts/diamonds, fill color = dark red; otherwise = black
    if (suit == HEARTS || suit == DIAMONDS)
        rankUpper.setFillColor(sf::Color(194, 25, 36));
    else
        rankUpper.setFillColor(sf::Color(0, 0, 0));

    // Setting face value (lower right of card) equal to face value (upper left)
    rankLower = rankUpper;
    // Rotating by 180 degrees
    rankLower.setRotation(180);
}

void SFMLRank::setPositionRankUpper(float x, float y) {
    rankUpper.setPosition(x, y);
}

void SFMLRank::setPositionRankLower(float x, float y) {
    rankLower.setPosition(x, y);
}


float SFMLRank::getPositionRankUpperX() {
    return rankUpper.getPosition().x;
}

float SFMLRank::getPositionRankUpperY() {
    return rankUpper.getPosition().y;
}

float SFMLRank::getPositionRankLowerX() {
    return rankLower.getPosition().x;
}

float SFMLRank::getPositionRankLowerY() {
    return rankLower.getPosition().y;
}

void SFMLRank::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    window.draw(rankLower);
    window.draw(rankUpper);
}

std::string SFMLRank::hoylePlayingCardFontKey(RanksEnum rank) {
    switch (rank) {
        case TWO:
            return "2";
            break;
        case THREE:
            return "3";
            break;
        case FOUR:
            return "4";
            break;
        case FIVE:
            return "5";
            break;
        case SIX:
            return "6";
            break;
        case SEVEN:
            return "7";
            break;
        case EIGHT:
            return "8";
            break;
        case NINE:
            return "9";
            break;
        case TEN:
            return "0";
            break;
        case JACK:
            return "a";
            break;
        case QUEEN:
            return "s";
            break;
        case KING:
            return "d";
            break;
        case ACE:
            return "f";
    }
}

#endif //POKER_SFMLRANK_H
