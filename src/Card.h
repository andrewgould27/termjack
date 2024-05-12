#ifndef CARD_H
#define CARD_H

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

    private:
    Rank m_rank;
    Suit m_suit;
};

#endif