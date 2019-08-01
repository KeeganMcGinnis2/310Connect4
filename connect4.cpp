#include "board.h"
#include "players.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    connect4Board game_board;
<<<<<<< HEAD
    int player1, player2, heuristic;
    Human hp1, hp2;
    Computer cp1, cp2;
    bool human1, human2;
    
    cout << "Please enter 1 if player 1 should be human, and 2 if player 1 should be an AI:\n";
    cin >> player1;
    while(player1 != 1 && player1 != 2) {
         cout << "Please enter 1 if player 1 should be human, and 2 if player 1 should be an AI:\n";
         cin >> player1;
    }

    if(player1 == 1) {
        Human hp1("p1");
        human1 = true;
    }

    else {
        cout << "Please enter 1 if player 1 should use a heuristic, and 2 if it should not:\n";
        cin >> heuristic;
        
        while(heuristic != 1 && heuristic != 2) {
            cout << "Please enter 1 if player 1 should use a heuristic, and 2 if it should not:\n";
            cin >> heuristic;
        }

        if(heuristic == 1) {
            Computer cp1("Heuristic1", 1000, true);
            human1 = false;
        }
        
        else {
            Computer cp1("Pure1", 1000, false);
            human1 = false;
        }
    }

    cout << "Please enter 1 if player 2 should be human, and 2 if player 2 should be an AI:\n";
    cin >> player2;
    while(player2 != 1 && player2 != 2) {
         cout << "Please enter 1 if player 2 should be human, and 2 if player 2 should be an AI:\n";
         cin >> player2;
    }

    if(player2 == 1) {
        Human hp2("p2");
        human2 = true;
    }

    else {
        cout << "Please enter 1 if player 2 should use a heuristic, and 2 if it should not:\n";
        cin >> heuristic;
        
        while(heuristic != 1 && heuristic != 2) {
            cout << "Please enter 1 if player 2 should use a heuristic, and 2 if it should not:\n";
            cin >> heuristic;
        }

        if(heuristic == 1) { 
            Computer cp2("Heuristic1", 1000, true);
            human2 = false;
        }
        
        else {
            Computer cp2("Pure1", 1000, false);
            human2 = false;
        }
    }
    
    
=======
    //Human player("ryan.py");
    Computer AI("AI", 1000, true);
    Computer player("AI", 100, false);
>>>>>>> 3077097c850096a1d29135096de6b5ee0ff56bef
    int index;
    cout << game_board << "\n";
    while(!game_board.isFull()) {
        if(human1 == true) 
            index = hp1.chooseMove(game_board);
        else
            index = cp1.chooseMove(game_board);

        while(game_board.columnFull(index)) {
            cout << "column is full, pick another column\n";
            if(human1 == true)
                index = hp1.chooseMove(game_board);
            else
                index = cp1.chooseMove(game_board);
        }
        game_board.setIndex(index);
        if(game_board.checkWin() || game_board.isFull()) {
            cout << "p1 wins!!!\n";
            break;
        }
        cout << game_board << "\n";
        game_board.swapTurn();
        if(human2 == true)
            index = hp2.chooseMove(game_board);
        else
            index = cp2.chooseMove(game_board);
        while(game_board.columnFull(index)) {
            cout << "column is full, pick another column\n";
            if(human2 == true)
            index = hp2.chooseMove(game_board);
        else
            index = cp2.chooseMove(game_board);
        }
        game_board.setIndex(index);
        if(game_board.checkWin() || game_board.isFull()) {
            cout << "p2 wins!!!\n";
            break;
        }
        cout << game_board << "\n";
        game_board.swapTurn();

    }

    cout << "\n" << game_board << "\n";
    return 0;
}