#ifndef DEALER_H
#define DEALER_H

class Dealer {
    public:
    Dealer();

    void addCard(Card card);

    Hand getHand();
    void displayHand(bool isPlayerTurn);
    void clearHand();
    int getHandValue();

    private:
    Hand m_hand;
};

#endif