#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class connect4Board {
    public:
        connect4Board();

        connect4Board(vector<char> b);

        vector<char> getBoard();

        void setIndex(const int col);

        void swapTurn();

        char getTurn();

        bool columnFull(int col);

        vector<int> legalMoves();

        bool isFull();

        bool checkWin();

        bool checkHorizontal();

        bool checkVertical();

        bool checkDiagonal();

        int getThrees();

        //int getTwos();

        friend ostream &operator << (ostream &output, const connect4Board &game_board);

    private:
        vector<char> board;
        char turn;

};

#endif