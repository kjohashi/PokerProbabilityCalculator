#include "Deck.h"
#include <iostream>
#include <ctime>

bool Deck::empty() {
return (cardIndex>DECK_SIZE);
}

Deck::Deck() {
// Fill by suits (i) then fill in numbers(j)
for(int i=0;i<4;i++){
    for(int j=0;j<13;j++) {
        deck[j+(13*i)].setSuit(static_cast<suits>(i));
            deck[j+(13*i)].setRank(static_cast<ranks>(j));
            }
        }
    cardIndex=0;
}

BaseCard Deck::getCardAt(int index) {
    return deck[index];
}

std::ostream &operator<<(std::ostream &out, const Deck &deck) {
    for(int i=0;i< deck.getSize();i++){
        std::cout<< deck.deck[i] <<std::endl;
        }
    return out;
}

BaseCard Deck::dealCard() {
// Copies the value of cardIndex first so that it doesnt get changed when you add 1 to it.
            int index = cardIndex;
        cardIndex++;
    return deck[index];
}

void Deck::shuffle() {
    for(int i=0;i<DECK_SIZE;i++){
        // selecting an index from 0- index
        int j = rand()% (i+1);
            swap(deck[i],deck[j]);
            }
        //Shuffle it twice
    for(int i=0;i<DECK_SIZE;i++){
    // selecting an index from 0- index
        int j = rand()% (i+1);
    swap(deck[i],deck[j]);
    }
}

void Deck::swap(BaseCard &card1, BaseCard &card2) {
    BaseCard temp;
    temp=card1;
    card1=card2;
    card2=temp;
}

int Deck::getSize() const {
    return DECK_SIZE;
}