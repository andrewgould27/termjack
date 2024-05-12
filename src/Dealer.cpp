#include <vector>

#include "Hand.h"
#include "Dealer.h"

Dealer::Dealer() : m_hand() {}

void Dealer::addCard(Card card) {
    m_hand.addCard(card);
}

Hand Dealer::getHand() {
    return m_hand;
}

void Dealer::displayHand(bool isPlayerTurn) {
    m_hand.displayHand(isPlayerTurn);
}

void Dealer::clearHand() {
    m_hand = Hand();
}

int Dealer::getHandValue() {
    return m_hand.getValue();
}