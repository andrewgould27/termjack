#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Hand.h"

class Player {
    public:
    Player();

    void hit(Deck &deck);
    void stand();

    int getHandValue();

    void addCard(Card card);
    void displayHand();
    void clearHand();
    
    private:
    Hand m_hand;
};

#endif