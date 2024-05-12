#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class Game {
    public:
    Game();
    void play();

    private:
    Deck m_deck;
    Player m_player;
    Dealer m_dealer;

    void initializeRound();
    void playerTurn();
    void dealerTurn();

    bool isGameOver();

    void displayResult();
    void displayGameState();
};

#endif 