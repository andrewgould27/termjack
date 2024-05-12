#include "Game.h"

#include <iostream>

Game::Game() : m_deck(6), m_player(), m_dealer() {}

void Game::initializeRound() {
    // Reset deck and hands 
    m_deck.shuffle();
    m_player.clearHand();
    m_dealer.clearHand();

    m_player.addCard(m_deck.drawCard());
    m_dealer.addCard(m_deck.drawCard());
    m_player.addCard(m_deck.drawCard());
    m_dealer.addCard(m_deck.drawCard());
}

void Game::playerTurn() {

}

void Game::dealerTurn() {

}

bool Game::isGameOver() {
    return m_player.getHandValue() > 21 || m_dealer.getHandValue() > 21;
}

void Game::play() {
    std::cout << "Welcome to TermJack!" << std::endl;

    while (!isGameOver()) {
        initializeRound();
        playerTurn();
        dealerTurn();
        displayResult();
        std::cout << std::endl;
    }

    std::cout << "Thanks for playing" << std::endl;
}

void Game::displayResult() {
    // win or lose 
    displayGameState();

    int playerValue = m_player.getHandValue();
    int dealerValue = m_dealer.getHandValue();

    if (playerValue > 21)      std::cout << "Player busts! Dealer wins." << std::endl;
    else if (dealerValue > 21) std::cout << "Dealer busts! Player wins." << std::endl;
    else if (playerValue > dealerValue) std::cout << "Player wins!" << std::endl;
    else if (dealerValue > playerValue) std::cout << "Dealer wins!" << std::endl;
    else std::cout << "It's a push. Nobody wins!" << std::endl;
}

void Game::displayGameState() {
    // Construct a screen buffer or something idk
    std::cout << "Dealer's hand: ";
    m_dealer.displayHand();
    std::cout << "Player's Hand: ";
    m_player.displayHand();
}