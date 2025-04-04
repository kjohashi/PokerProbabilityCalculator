#ifndef POKERANALYSIS_CARDHAND_H
#define POKERANALYSIS_CARDHAND_H

#include "Deck.h"
#include <iostream>
#include <vector>

class CardHand {
private:
    std::vector<BaseCard> hand;
public:
    CardHand();
    void addCard(BaseCard card);
    friend std::ostream& operator<<(std::ostream& out, const CardHand& hand);
    int getSize() const;
    int getCardValueAt(int index);
    BaseCard& getCardAt(int index);
};
#endif //POKERANALYSIS_CARDHAND_H