#include "Hand.h"

Hand::Hand() {
    m_cards = std::vector<Card>();
}

/**
 * Adds card to the hand's card vector 
 * @param card Card to be added
 */
void Hand::addCard(Card card) {
    m_cards.emplace_back(card);
}

/**
 * Calculates the value of the hand according to the rules of blackjack
 */
int Hand::getValue() {
    int sum = 0;
    for (Card card : m_cards)
        sum += card.getValue();

    // Probably add something about handling aces, stupid blackjack

    return sum;
}