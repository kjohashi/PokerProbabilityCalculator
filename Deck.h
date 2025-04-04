#ifndef POKERANALYSIS_DECK_H
#define POKERANALYSIS_DECK_H
#include "BaseCard.h"
#include "CardVariables.h"
class Deck {
private:
    int cardIndex; //marks the index of the next card in the deck
    BaseCard deck[52];// this is your final deck of cards
    const int DECK_SIZE = 52;// this is the size of your deck
public:
    Deck(); // this is the constructor
    bool empty(); //returns true if deck has no cards
    void shuffle(); // puts cards in random order
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
    BaseCard dealCard(); // returns the next card in the deck
    BaseCard getCardAt(int index);// gets the Card at the given index
    void swap(BaseCard& card1,BaseCard& card2);
    int getSize() const;
};

#endif
