#include "PokerScore.h"

PokerScore::PokerScore() = default;

    PokerScore::Scores &PokerScore::operator[](unsigned int index) {
return scores[index];
}

int PokerScore::size() const{
return scores.size();
}

bool PokerScore::hasRoyalFlush(CardHand sortedHand) {
    //check if all the cards are the same suit first;
    for(int i=0;i<sortedHand.getSize()-1;i++) {
        if (sortedHand.getCardAt(i).getSuit()!=sortedHand.getCardAt(i+1).getSuit())
            return false;
}
    // Then check if it contains all the cards required;
        if(sortedHand.getCardAt(0).getRank()!= ACE)
            return false;

    for(int i=1;i<sortedHand.getSize();i++) {
        if (sortedHand.getCardAt(i).getRankValue() != i+9)
            return false;
        }
            return true;
    }

bool PokerScore::hasStraightFlush(const CardHand& sortedHand) {
    //check if all the cards are the same suit first;
    return hasStraight(sortedHand) && hasFlush(sortedHand);
}

bool PokerScore::hasFourOfAKind(CardHand sortedHand) {
    int tracker = 0;
    for (int i = 0; i < 2; i++)
    if (sortedHand.getCardAt(i).getRankValue() != sortedHand.getCardAt(i + 3).getRankValue())
tracker++;
return (tracker == 1);
}

bool PokerScore::hasFullHouse(CardHand sortedHand) {
// has to check either to see if first 2 are pair then if rest 3 are 3 of kind.
//case 1 : Pairs then set of 3
// Checks to see if its a pair and not a 3 of a kind
    if(sortedHand.getCardAt(0).getRankValue()==sortedHand.getCardAt(1).getRankValue()&&
    sortedHand.getCardAt(0).getRankValue()!=sortedHand.getCardAt(2).getRankValue()){
// now check for 3 of a kind.
    if(hasThreeOfAKind(sortedHand))
    return true;
}
//case 2: 3 of a kind then a pair
// checks for 3 of a kind first
    if(sortedHand.getCardAt(0).getRankValue()==sortedHand.getCardAt(1).getRankValue()&&
    sortedHand.getCardAt(0).getRankValue()==sortedHand.getCardAt(2).getRankValue()){
// now check for pair
    if(sortedHand.getCardAt(3).getRankValue()==sortedHand.getCardAt(4).getRankValue())
return true;
}
return false;
}


bool PokerScore::hasFlush(CardHand sortedHand) {
    for(int i=0;i<sortedHand.getSize()-1;i++) {
        if (sortedHand.getCardAt(i).getSuit()!=sortedHand.getCardAt(i+1).getSuit())
    return false;
}
return true;
}

bool PokerScore::hasStraight(CardHand sortedHand) {
for(int i=0;i<sortedHand.getSize()-1;i++) {
    if (sortedHand.getCardAt(i).getRankValue()!=sortedHand.getCardAt(i+1).getRankValue()-1)
        return false;
}
        return true;
}

bool PokerScore::hasThreeOfAKind(CardHand sortedHand) {
// save some time
    if(!hasOnePair(sortedHand))
    return false;
// check first set
    if(sortedHand.getCardAt(0).getRankValue()==sortedHand.getCardAt(1).getRankValue()&&
sortedHand.getCardAt(0).getRankValue()==sortedHand.getCardAt(2).getRankValue())
    return true;
// check set set
    if(sortedHand.getCardAt(1).getRankValue()==sortedHand.getCardAt(2).getRankValue()&&
sortedHand.getCardAt(1).getRankValue()==sortedHand.getCardAt(3).getRankValue())
    return true;
// check third set
    if(sortedHand.getCardAt(2).getRankValue()==sortedHand.getCardAt(3).getRankValue()&&
sortedHand.getCardAt(2).getRankValue()==sortedHand.getCardAt(3).getRankValue())
    return true;
return false;
}

bool PokerScore::hasTwoPair(CardHand sortedHand) {
    int tracker=0;
    if(hasThreeOfAKind(sortedHand))
        return false;
    for(int i=0;i<sortedHand.getSize()-1;i++){
        if(sortedHand.getCardAt(i).getRankValue()==sortedHand.getCardAt(i+1).getRankValue()) {
    tracker++;
    }
}
return (tracker==2);
}

bool PokerScore::hasOnePair(CardHand sortedHand) {
    for(int i=0;i<sortedHand.getSize()-1;i++){
    if(sortedHand.getCardAt(i).getRankValue()==sortedHand.getCardAt(i+1).getRankValue())
    return true;
    }
    return false;
}
bool PokerScore::hasHighCard(const CardHand& sortedHand) {
    if(sortedHand.getSize()>0)
    return true;
}

void PokerScore::addScore(PokerScore::Scores score) {
scores.push_back(score);
}

void PokerScore::operator+=(const PokerScore::Scores &score) {
this->addScore(score);
}

bool operator==(const PokerScore &p, PokerScore::Scores score) {
// I think this is how this is supposed to work?
for(int i=0;i<p.size();i++){
if(p.getScoreAt(i)==score)
return true;
    }
}

PokerScore::Scores PokerScore::getScoreAt(int index) const{
return scores[index];
}

void PokerScore::operator+=(const PokerScore &score) {
for(int i=0;i<score.size();i++){
this->addScore(score.getScoreAt(i));
    }
}

std::ostream &operator<<(std::ostream &out,const PokerScore &score) {

    int ROYAL_FLUSH=0,STRAIGHT_FLUSH=0,FOUR_OF_A_KIND=0,FULL_HOUSE=0,FLUSH=0,
    STRAIGHT=0,THREE_OF_A_KIND=0,TWO_PAIR=0,ONE_PAIR=0,HIGH_CARD=0;
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
out <<"Royal Flush: " << ROYAL_FLUSH <<std::endl
<< "Straight Flush: " << STRAIGHT_FLUSH <<std::endl
<< "Four of a Kind: "<< FOUR_OF_A_KIND <<std::endl
<< "Full House: "<< FULL_HOUSE <<std::endl
<< "Flush: " << FLUSH <<std::endl
<< "Straight: "<< STRAIGHT <<std::endl
<< "Three of a Kind: "<<THREE_OF_A_KIND <<std::endl
<< "Two Pair: "<< TWO_PAIR <<std::endl
<< "One Pair: "<< ONE_PAIR <<std::endl
<< "High Card: "<< HIGH_CARD <<std::endl;
return out;
}