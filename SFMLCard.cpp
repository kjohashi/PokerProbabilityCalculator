#include "SFMLCard.h"


SFMLCard::SFMLCard() {
    // Intentionally blank
}

SFMLCard::SFMLCard(ranks, suits) {
    // Intentionally blank
}

SFMLCard::SFMLCard(ranks, suits, float positionX, float positionY) {

    background.setBackground();

    this->setPosition(positionX, positionY);

    this->rank.setRank(rank, suit);

    // Position = pixels away from both the left/top of the card
    this->rank.setPositionRankUpper(getPositionX() + 7, getPositionY() - 5);

    // Position = pixels away from both the right/ bottom of the card
    this->rank.setPositionRankLower(getPositionX() + background.getWidth() - 7, getPositionY() + background.getHeight() + 5);

    this->suit.setSuit(suit);

    // Position = middle of cardBackground.
    this->suit.setPositionSuitMiddle(getPositionX() + background.getWidth() / 3.8, getPositionY() + background.getHeight() / 3.95);

    // Position = pixels below rankUpper.
    this->suit.setPositionSuitUpper(this->rank.getPositionRankUpperX() - 0.5, this->rank.getPositionRankUpperY() + 31);

    // Position = pixels above rankLower.
    this->suit.setPositionSuitLower(this->rank.getPositionRankLowerX() + 0.5, this->rank.getPositionRankLowerY() - 31);

}

void SFMLCard::setCard(ranks, suits, float positionX, float positionY) {
    setBackground();
    setPosition(positionX, positionY);
    setRank(rank, suit);
    setSuit(suit);
}

void SFMLCard::setRank(ranks, suits) {
    this->rank.setRank(rank, suit);

    // Position = pixels away from both the left/top of the card
    this->rank.setPositionRankUpper(getPositionX() + 7, getPositionY() - 5);

    // Position = pixels away from both the right/ bottom of the card
    this->rank.setPositionRankLower(getPositionX() + background.getWidth() - 7, getPositionY() + background.getHeight() + 5);
}

void SFMLCard::setSuit(suits) {
    this->suit.setSuit(suit);

    // Position = middle of cardBackground.
    this->suit.setPositionSuitMiddle(getPositionX() + background.getWidth() / 3.8, getPositionY() + background.getHeight() / 3.95);

    // Position = pixels below rankUpper.
    this->suit.setPositionSuitUpper(this->rank.getPositionRankUpperX() - 0.5, this->rank.getPositionRankUpperY() + 31);

    // Position = pixels above rankLower.
    this->suit.setPositionSuitLower(this->rank.getPositionRankLowerX() + 0.5, this->rank.getPositionRankLowerY() - 31);
}

void SFMLCard::setBackground() {
    background.setBackground();
}

void SFMLCard::setPosition(float x, float y) {
    background.setPosition(x, y);

}

float SFMLCard::getPositionX() {
    return background.getPosition().x;
}

float SFMLCard::getPositionY() {
    return background.getPosition().y;
}

float SFMLCard::getWidth() {
    return background.getWidth();
}

float SFMLCard::getHeight() {
    return background.getHeight();
}

void SFMLCard::draw(sf::RenderTarget &window, sf::RenderStates state) const {
   window.draw(background);
   window.draw(rank);
   window.draw(suit);

}