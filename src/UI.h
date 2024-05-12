#ifndef UI_H 
#define UI_H

#include "Card.h"
#include "Hand.h"

#include <iostream>
#include <vector>
#include <string>

class UI {
    public: 
    void clearScreen();
    void drawHand(Hand hand);
    void drawHand(Hand hand, bool isPlayerTurn);
    private:
    std::vector<std::string> drawCard(Card card);
};

#endif 