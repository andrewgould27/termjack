#include <string>
#include <stdexcept>

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

std::string Card::getRank() {
    switch (m_rank) {
        case ACE: return "A";
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "J";
        case QUEEN: return "Q";
        case KING: return "K";
        default: throw std::logic_error("For some reason this card doesn't map to a rank?");
    }
}

std::string Card::getSuit() {
    switch (m_suit) {
        case SPADES:
            return "♠";
        case CLUBS:
            return "♣";
        case HEARTS:
            return "♥";
        case DIAMONDS:
            return "♦";
        default:
            throw std::logic_error("For some reason, there's no mapping for this suit.");
    }
}