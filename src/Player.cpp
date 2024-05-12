#include "Player.h"

Player::Player() {

}

void Player::hit(Deck &deck) {
    Card card = deck.drawCard();
    m_hand.addCard(card);
}

void Player::stand() {
    // Is this even necessary, idk
}

int Player::getHandValue() {
    return m_hand.getValue();
}
