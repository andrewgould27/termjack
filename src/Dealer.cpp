#include <vector>

#include "Hand.h"
#include "Dealer.h"

Dealer::Dealer() : m_hand() {}

void Dealer::addCard(Card card) {
    m_hand.addCard(card);
}

void Dealer::displayHand() {
    m_hand.displayHand();
}

void Dealer::clearHand() {
    m_hand = Hand();
}

int Dealer::getHandValue() {
    return m_hand.getValue();
}