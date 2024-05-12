#include <iostream>

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

void Hand::displayHand() {
    for (Card card : m_cards)
        std::cout << card.getRank() << card.getSuit() << " ";
    std::cout << std::endl;
}

void Hand::displayHand(bool isPlayerTurn) {
    if (!isPlayerTurn)
        for (Card card : m_cards)
            std::cout << card.getRank() << card.getSuit() << " ";
    else 
        std::cout << m_cards[0].getRank() << m_cards[0].getSuit() << " ";
    std::cout << std::endl;
}

std::vector<Card> Hand::getCards() {
    return m_cards;
}