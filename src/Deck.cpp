#include "Card.h"
#include "Deck.h"

#include <stdexcept>
#include <stdlib.h>

Deck::Deck(int num_decks = 6) {
    for (int i = 0; i < num_decks; i++) 
        for (int suit = Card::CLUBS; suit <= Card::SPADES; suit++)
            for (int rank = Card::ACE; rank <= Card::KING; rank++)
                m_cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
}

void Deck::shuffle() {
    if (m_cards.size() == 0) 
        throw std::logic_error("Cannot shuffle an empty deck.");

    for (int i = m_cards.size() - 1; i > 0; i--)  {
        int r = rand() % (i + 1);
        std::swap(m_cards[i], m_cards[r]);
    }
}

Card Deck::drawCard() {
    if (m_cards.empty())
        throw std::logic_error("Cannot draw from an empty deck.");
    
    Card card = m_cards.back();
    m_cards.pop_back();
    return card;
}