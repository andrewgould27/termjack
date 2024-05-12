#include "Game.h"

#include <iostream>

Game::Game() : m_deck(6), m_player(), m_dealer(), m_ui() {}

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

void Game::initializeRound() {
    // Reset deck and hands 
    m_deck.shuffle();
    m_player.clearHand();
    m_dealer.clearHand();

    // Set to player's turn
    m_isPlayerTurn = true;

    // Deal cards
    m_player.addCard(m_deck.drawCard());
    m_dealer.addCard(m_deck.drawCard());
    m_player.addCard(m_deck.drawCard());
    m_dealer.addCard(m_deck.drawCard());
}

void Game::playerTurn() {
    m_isPlayerTurn = true;
    while (m_player.getHandValue() < 21) {
        displayGameState();
        std::cout << "Do you want to [h]it or [s]tand? ";
        char choice;
        std::cin >> choice;

        if (choice == 'h') 
            m_player.addCard(m_deck.drawCard());
        else if (choice == 's') 
            break;
        else 
            std::cout << "Invalid choice. Try again." << std::endl;
    }
}

void Game::dealerTurn() {
    m_isPlayerTurn = false;
    while (m_dealer.getHandValue() < 17)
        m_dealer.addCard(m_deck.drawCard());
}

bool Game::isGameOver() {
    return m_player.getHandValue() > 21 || m_dealer.getHandValue() > 21;
}

void Game::displayResult() {
    // win or lose 
    displayGameState();

    int playerValue = m_player.getHandValue();
    int dealerValue = m_dealer.getHandValue();

    if (playerValue > 21) {
        std::cout << "Player busts! Dealer wins." << std::endl;
    } else if (dealerValue > 21) {
        std::cout << "Dealer busts! Player wins." << std::endl;
    } else if (playerValue > dealerValue) {
        std::cout << "Player wins!" << std::endl;
    } else if (dealerValue > playerValue) {
        std::cout << "Dealer wins!" << std::endl;
    } else {
        std::cout << "It's a push. Nobody wins!" << std::endl;
    }
}

void Game::displayGameState() {
    m_ui.clearScreen();
    std::cout << "Dealer's hand:\n";
    m_ui.drawHand(m_dealer.getHand(), m_isPlayerTurn);
    std::cout << "Player's Hand:\n";
    m_ui.drawHand(m_player.getHand());

    
}