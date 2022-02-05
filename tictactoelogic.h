// Temporary file with tictactoe logic. In future, all logic will be moved to
// server

#ifndef CLIENT_PROTOTYPE_TICTACTOELOGIC_H
#define CLIENT_PROTOTYPE_TICTACTOELOGIC_H
#include <random>
#include <vector>

namespace tictactoe {

class tictactoelogic {
public:
    tictactoelogic() : gen(rd()), dis(0.0, 1.0){};

    void restartGame();

    bool makeMove(int pos, char player);

    bool canPlayAtPos(int pos);

    void computerTurn();

    void smartAI();

    void randomAI();

    std::vector<char> get_board();

private:
    bool running = false;
    double difficulty = 1.0;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    std::vector<char> board = std::vector<char>(9, ' ');
};

bool winner(std::vector<char> board);

}  // namespace tictactoe

#endif  // CLIENT_PROTOTYPE_TICTACTOELOGIC_H
