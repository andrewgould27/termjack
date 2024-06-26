#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
    public:
    Deck(int num_decks);

    void shuffle();
    Card drawCard();

    size_t size();

    private:
    std::vector<Card> m_cards;
};

#endif 