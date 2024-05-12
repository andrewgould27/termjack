#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "UI.h"

class Game {
    public:
    Game();
    void play();

    private:
    Deck m_deck;
    Player m_player;
    Dealer m_dealer;
    UI m_ui;

    bool m_isPlayerTurn;

    size_t playerWins = 0, dealerWins = 0;

    void initializeRound();
    void playerTurn();
    void dealerTurn();

    bool isGameOver();

    void displayResult();
    void displayGameState();
};

#endif 