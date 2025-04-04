#ifndef POKERANALYSIS_CARDHANDSCORER_H
#define POKERANALYSIS_CARDHANDSCORER_H

#include "PokerScore.h"

class CardHandScorer {
public:
    static void sort(CardHand& hand);
    static void swap(BaseCard& card1, BaseCard& card2);
    static PokerScore scorePokerHand(CardHand hand);
    static void displayScores(const PokerScore& score);
};


#endif //POKERANALYSIS_CARDHANDSCORER_H