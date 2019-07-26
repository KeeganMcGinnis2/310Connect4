#include "board.h"
#include "players.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    connect4Board game_board;
    Human player("ryan.py");
    Computer AI("AI", 1000);
    int index;
    while(!game_board.isFull()) {
        index = player.chooseMove(game_board);
        while(game_board.columnFull(index)) {
            cout << "column is full, pick another column\n";
            index = player.chooseMove(game_board);
        }
        game_board.setIndex(index);
        if(game_board.checkWin() || game_board.isFull()) {
            break;
        }
        cout << game_board << "\n";
        game_board.swapTurn();
        index = AI.chooseMove(game_board);
        while(game_board.columnFull(index)) {
            cout << "column is full, pick another column\n";
            index = AI.chooseMove(game_board);
        }
        game_board.setIndex(index);
        if(game_board.checkWin() || game_board.isFull()) {
            break;
        }
        cout << game_board << "\n";
        game_board.swapTurn();

    }

    cout << game_board << "\n";
    return 0;
}