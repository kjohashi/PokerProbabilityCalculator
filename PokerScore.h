#ifndef POKERANALYSIS_POKERSCORE_H
#define POKERANALYSIS_POKERSCORE_H

#include "CardHand.h"
class PokerScore {


public:
enum Scores{

ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

FOUR_OF_A_KIND, //four cards of the same ranking

FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

FLUSH, //five cards of the same suit

STRAIGHT, //five cards in consecutive ranking

THREE_OF_A_KIND, //three cards of the same rank

TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

ONE_PAIR, //two cards of the same rank

HIGH_CARD //highest card in the player’s sortedHand

};

void operator+=(const Scores& score);
void operator+=(const PokerScore& score);
friend bool operator==(const PokerScore& p, Scores score);
friend std::ostream& operator<<(std::ostream& out,const PokerScore& score);
int size() const;
Scores& operator[](unsigned int index);
PokerScore();
static bool hasRoyalFlush(CardHand sortedHand);
static bool hasStraightFlush(const CardHand& sortedHand);
static bool hasFourOfAKind(CardHand sortedHand);
static bool hasFullHouse(CardHand sortedHand);
static bool hasFlush(CardHand sortedHand);
static bool hasStraight(CardHand sortedHand);
static bool hasThreeOfAKind(CardHand sortedHand);
static bool hasTwoPair(CardHand sortedHand);
static bool hasOnePair(CardHand sortedHand);
static bool hasHighCard(const CardHand& sortedHand);

void addScore(Scores score);
Scores getScoreAt(int index) const;
private:
std::vector<Scores> scores;

};


#endif //POKERANALYSIS_POKERSCORE_H