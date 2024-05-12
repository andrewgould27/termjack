#include "Card.h"

Card::Card(Rank rank, Suit suit) {
    m_rank = rank;
    m_suit = suit;
}

int Card::getValue() const {
    if (m_rank >= TWO && m_rank <= TEN)
        return static_cast<int>(m_rank);
    else if (m_rank == JACK || m_rank == QUEEN || m_rank == KING)
        return 10;
    else if (m_rank == ACE)
        return 11;
    return 0;
}