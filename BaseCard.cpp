#include "BaseCard.h"
#include <string>
#include <iostream>

void BaseCard::setRank(ranks rank) {
BaseCard::rank = rank;
}

void BaseCard::setSuit(suits suit) {
BaseCard::suit = suit;
}

std::string BaseCard::convertRankToString(ranks rank) const {
    switch(rank){
        case ACE:
            return "A" ;
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case TEN:
            return "10";
        case JACK:
            return "J";
        case QUEEN:
            return "Q";
        case KING:
            return "K";
        default:
            return "A";
        }
    }
std::string BaseCard::convertSuitToString(suits suit) const {
    switch(suit){
        case SPADES:
            return "Spades";
        case CLUBS:
            return "Clubs";
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Hearts";
}
}


BaseCard::BaseCard(ranks rank, suits suit) : rank(rank), suit(suit) {
}

BaseCard::BaseCard() {
rank= ACE;
suit= HEARTS;
}

int BaseCard::getRankValue() const {
switch(rank){
    case ACE:
        return 1;
    case TWO:
        return 2;
    case THREE:
        return 3;
    case FOUR:
        return 4;
    case FIVE:
        return 5;
    case SIX:
        return 6;
    case SEVEN:
        return 7;
    case EIGHT:
        return 8;
    case NINE:
        return 9;
    case TEN:
        return 10;
    case JACK:
        return 11;
    case QUEEN:
        return 12;
    case KING:
        return 13;
}
}

int BaseCard::getSuitValue() {
    return suit+1;
}

suits BaseCard::getSuit() const {
    return suit;
}

ranks BaseCard::getRank() const {
    return rank;
}

std::ostream &operator<<(std::ostream &out, const BaseCard &card) {
    std::cout <<
    card.convertRankToString(card.getRank()) <<" of "<<
    card.convertSuitToString(card.getSuit());
    return out;
}

int operator+(const BaseCard &card1,const BaseCard &card2) {
    int sum =card1.getRankValue()+card2.getRankValue();
    return sum;
}