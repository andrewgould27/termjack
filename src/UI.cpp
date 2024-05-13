#include "UI.h"

/**
 * Clears the terminal screen using ANSI escape codes
 */
void UI::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
}

/**
 * Creates a 5*7 vector of strings to be passed to the drawHand function.
 * This constructs a complete buffer that is pushed to stdout all at once. 
 * @param Card The card to generate
 * @returns A vector of strings, in the order they should be printed
 */
std::vector<std::string> UI::drawCard(Card card) {
    // This is all hacky, the nbsp is a 2*4 byte width character, so it requires some finageling to
    // get it to display right.
    std::string space = "          ";

    std::string top = "┌─────┐";
    std::string left_rank = "│" + card.getRank() + space.substr(0, (5 - card.getRank().size()) * 2) + "│";
    std::string center_suit = "│  " + card.getSuit() + "  │";
    std::string right_rank = "│" + space.substr(0, (5 - card.getRank().size()) * 2) + card.getRank() + "│";
    std::string bottom = "└─────┘";

    return { top, left_rank, center_suit, right_rank, bottom };
}

/**
 * Constructs an entire screen buffer for the hand in question
 * and pushes the buffer to stdout
 * @param Hand The hand to display
 */
void UI::drawHand(Hand hand) {
    std::vector<Card> cards = hand.getCards();
    std::vector<std::vector<std::string>> card_strs;
    for (Card card : cards) {
        card_strs.emplace_back(drawCard(card));
    }

    for (size_t i = 0; i < card_strs[0].size(); i++) {
        std::string curr = "";
        for (std::vector<std::string> vec : card_strs) {
            curr += vec[i];
        }
        std::cout << curr << "\n";
    }    
}

/**
 * Constructs an entire screen buffer for the hand in question
 * and pushes the buffer to stdout
 * @param Hand The hand to display
 * @param bool Is it the player's turn?
 */
void UI::drawHand(Hand hand, bool isPlayerTurn) {
    std::vector<Card> cards = hand.getCards();
    std::vector<std::vector<std::string>> card_strs;
    for (Card card : cards) {
        card_strs.emplace_back(drawCard(card));
    }

    if (!isPlayerTurn) {
        for (size_t i = 0; i < card_strs[0].size(); i++) {
            std::string curr = "";
            for (std::vector<std::string> vec : card_strs) {
                curr += vec[i];
            }
            std::cout << curr << "\n";
        }    
    } else {
        for (std::string str : card_strs[0]) 
            std::cout << str << "\n";
    }
}

void UI::displayScoreboard(int playerWins, int dealerWins) {
    std::string p_wins = "Player Wins: " + std::to_string(playerWins);
    std::string d_wins = "Dealer Wins: " + std::to_string(dealerWins);
    std::string space = "          ";

    std::cout << "┌────────────────────────┬────────────────────────┐\n";
    std::cout << "│ " + p_wins + space.substr(0, (23 - p_wins.size()) * 2) + "│ " + d_wins + space.substr(0, (23 - p_wins.size()) * 2) + "│\n";
    std::cout << "└────────────────────────┴────────────────────────┘\n";
}