#include "board.h"
#include "players.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Computer PureAI("Pure", 1000, false);
    Computer HeuristicAI("Heuristic", 1000, true);

    int i, index;
    int pure_victories = 0, heuristic_victories = 0;
    int games_played = 5;
    //Pure goes first
    for(i=0;i<games_played;i++) {
        connect4Board game_board;
        while(!game_board.isFull()) {
            index = PureAI.chooseMove(game_board);
            game_board.setIndex(index);
            if(game_board.checkWin() || game_board.isFull()) {
                pure_victories++;
                break;
            }

            game_board.swapTurn();
            index = HeuristicAI.chooseMove(game_board);
            game_board.setIndex(index);

            if(game_board.checkWin() || game_board.isFull()) {
                heuristic_victories++;
                break;
            }
            game_board.swapTurn();
        }
        cout << game_board << "\n";
    }

    cout << "Results with Pure AI going first: \n";
    cout << "Games Played: " << games_played << "\n";
    cout << "Pure Victories: " << pure_victories << "\n";
    cout << "Heuristic Victories: " << heuristic_victories << "\n";
    cout << "Draws: " << games_played - pure_victories - heuristic_victories << "\n";
    
    //Heuristic goes first
    pure_victories = 0, heuristic_victories = 0;
    for(i=0;i<games_played;i++) {
        connect4Board game_board;
        while(!game_board.isFull()) {
            index = HeuristicAI.chooseMove(game_board);
            game_board.setIndex(index);
            if(game_board.checkWin() || game_board.isFull()) {
                heuristic_victories++;
                break;
            }

            game_board.swapTurn();
            index = PureAI.chooseMove(game_board);
            game_board.setIndex(index);

            if(game_board.checkWin() || game_board.isFull()) {
                pure_victories++;
                break;
            }
            game_board.swapTurn();
        }
        cout << game_board << "\n";
    }

    cout << "Results with Heuristic AI going first: \n";
    cout << "Games Played: " << games_played << "\n";
    cout << "Pure Victories: " << pure_victories << "\n";
    cout << "Heuristic Victories: " << heuristic_victories << "\n";
    cout << "Draws: " << games_played - pure_victories - heuristic_victories << "\n";

    return 0;
}