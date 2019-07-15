#include "board.h"
#include "players.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    connect4Board game_board;
    Human playr;
    Human playa("ryan.py");
    int index;
    while(!game_board.isFull()) {
        index = playr.chooseMove();
        while(game_board.columnFull(index)) {
            cout << "column is full, pick another column\n";
            index = playr.chooseMove();
        }
        game_board.setIndex(index);
        if(game_board.checkWin()) {
            break;
        }
        cout << game_board << "\n";
        game_board.swapTurn();
        index = playa.chooseMove();
        game_board.setIndex(index);
        if(game_board.checkWin()) {
            break;
        }
        cout << game_board << "\n";
        game_board.swapTurn();

    }

    cout << game_board << "\n";
    return 0;
}