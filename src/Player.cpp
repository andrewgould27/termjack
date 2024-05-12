#include "Player.h"

Player::Player() : m_hand() {}

void Player::hit(Deck &deck) {
    Card card = deck.drawCard();
    m_hand.addCard(card);
}

void Player::stand() {
    // Is this even necessary, idk
}

void Player::addCard(Card card) {
    m_hand.addCard(card);
}

Hand Player::getHand() {
    return m_hand;
}

void Player::displayHand() {
    m_hand.displayHand();
}

void Player::clearHand() {
    m_hand = Hand();
}

int Player::getHandValue() {
    return m_hand.getValue();
}
