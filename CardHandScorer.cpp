static int ROYAL_FLUSH=0; //A, K, Q, J, 10, all the same suit.
static int STRAIGHT_FLUSH=0; //five cards of the same suit and consecutive ranking
static int FOUR_OF_A_KIND=0; //four cards of the same ranking
static int FULL_HOUSE=0;
static int FLUSH =0;
static int STRAIGHT=0;
static int THREE_OF_A_KIND=0;
static int TWO_PAIR=0;
static int ONE_PAIR=0;
static int HIGH_CARD=0;

#include "CardHandScorer.h"

void CardHandScorer::swap(BaseCard& card1, BaseCard& card2) {
    BaseCard temp;
    temp=card1;
    card1=card2;
    card2 =temp;
    }

    PokerScore CardHandScorer::scorePokerHand(CardHand hand) {
    PokerScore score;
    //Sort the Cards first
    CardHandScorer::sort(hand);
    //now we do the scoring.
    if(PokerScore::hasRoyalFlush(hand))
    score.addScore(PokerScore::ROYAL_FLUSH);
    if(PokerScore::hasStraightFlush(hand))
    score.addScore(PokerScore::STRAIGHT_FLUSH);
    if(PokerScore::hasFourOfAKind(hand))
    score.addScore(PokerScore::FOUR_OF_A_KIND);
    if(PokerScore::hasFullHouse(hand))
    score.addScore(PokerScore::FULL_HOUSE);
    if(PokerScore::hasFlush(hand))
    score.addScore(PokerScore::FLUSH);
    if(PokerScore::hasStraight(hand))
    score.addScore(PokerScore::STRAIGHT);
    if(PokerScore::hasThreeOfAKind(hand))
    score.addScore(PokerScore::THREE_OF_A_KIND);
    if(PokerScore::hasTwoPair(hand))
    score.addScore(PokerScore::TWO_PAIR);
    if(PokerScore::hasOnePair(hand))
    score.addScore(PokerScore::ONE_PAIR);
    if(PokerScore::hasHighCard(hand))
    score.addScore(PokerScore::HIGH_CARD);
return score;
}

void CardHandScorer::sort(CardHand& hand) {
    bool swapped;

    for(int i=0;i<hand.getSize();i++){
        swapped=false;
    for(int j=0;j<hand.getSize()-1;j++) {
    if (hand.getCardValueAt(j) > hand.getCardValueAt(j + 1)) {
    swap(hand.getCardAt(j), hand.getCardAt(j + 1));
    swapped=true;
    }
    }
    if(!swapped)
    break;
    }
    }

void CardHandScorer::displayScores(const PokerScore &score) {
    for(int i=0;i<score.size();i++)
    switch(score.getScoreAt(i)) {
    case PokerScore::ROYAL_FLUSH:
    ROYAL_FLUSH++;
    break;
    case PokerScore::STRAIGHT_FLUSH:
    STRAIGHT_FLUSH++;
    break;
    case PokerScore::FOUR_OF_A_KIND:
    FOUR_OF_A_KIND++;
    break;
    case PokerScore::FULL_HOUSE:
    FULL_HOUSE++;
    break;
    case PokerScore::FLUSH:
    FLUSH++;
    break;
    case PokerScore::STRAIGHT:
    STRAIGHT++;
    break;
    case PokerScore::THREE_OF_A_KIND:
    THREE_OF_A_KIND++;
    break;
    case PokerScore::TWO_PAIR:
    TWO_PAIR++;
    break;
    case PokerScore::ONE_PAIR:
    ONE_PAIR++;
    break;
    case PokerScore::HIGH_CARD:
    HIGH_CARD++;
    break;
    };

std::cout
<< "Royal Flush: " << ROYAL_FLUSH <<std::endl
<< "Straight Flush: " << STRAIGHT_FLUSH <<std::endl
<< "Four of a Kind: "<< FOUR_OF_A_KIND <<std::endl
<< "Full House: "<< FULL_HOUSE <<std::endl
<< "Flush: " << FLUSH <<std::endl
<< "Straight: "<< STRAIGHT <<std::endl
<< "Three of a Kind: "<<THREE_OF_A_KIND <<std::endl
<< "Two Pair: "<< TWO_PAIR <<std::endl
<< "One Pair: "<< ONE_PAIR <<std::endl
<< "High Card: "<< HIGH_CARD <<std::endl;
}