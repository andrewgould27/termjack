#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
    public:
    Hand();

    void displayHand();
    void displayHand(bool isPlayerTurn);

    void addCard(Card card);
    int getValue();

    std::vector<Card> getCards();

    private:
    std::vector<Card> m_cards;
};

#endif