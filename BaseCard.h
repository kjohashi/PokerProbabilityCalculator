#ifndef PLAYINGCARD_BASECARD_H
#define PLAYINGCARD_BASECARD_H

#include "CardVariables.h"
#include <string>

class BaseCard {
protected:
    suits suit;
    ranks rank;
public:
    suits getSuit() const;
    ranks getRank() const;
    BaseCard(ranks rank, suits suit);
    BaseCard();
    void setRank(ranks rank);
    void setSuit(suits suit);
    int getRankValue() const;
    int getSuitValue();
    std::string convertRankToString(ranks rank) const;
    std::string convertSuitToString(suits suit) const;
friend std::ostream &operator<<(std::ostream &out,const BaseCard &card);
friend int operator+(const BaseCard&card1,const BaseCard &card2);
};

#endif //PLAYINGCARD_BASECARD_H