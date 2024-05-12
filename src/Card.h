#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    public:
    enum Suit {
        CLUBS, DIAMONDS, HEARTS, SPADES
    };

    enum Rank {
        ACE = 1, 
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, KING, QUEEN
    };
    
    Card(Rank rank, Suit suit);
    int getValue() const;

    std::string getRank();
    std::string getSuit();

    private:
    Rank m_rank;
    Suit m_suit;
};

#endif