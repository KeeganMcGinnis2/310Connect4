#include "players.h"
#include "board.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

Player::Player() {
    name = "no_name";
}

Player::Player(string n) {
    name = n;
}

void Player::printName() {
    cout << name << "\n";
}

int Human::chooseMove(connect4Board board) {
    int move;
    cout << name << ", please enter a column for your move:\n";
    cin >> move;
    while(!cin || (move < 1 || move > 7)){
        cin.clear();
        cin.ignore();
        cout << "Invalid move, please enter a column for your move:\n";
        cin >> move;
    }
    return move;
}

Computer::Computer() {
    name = "nameless_ai";
    random_playouts = 300;
}

Computer::Computer(string n, int r, bool h) {
    name = n;
    random_playouts = r;
    heuristic = h;
}

int Computer::chooseMove(connect4Board board) {
    if(heuristic) 
        return heuristicMCTS(board);
    else
        return pureMCTS(board);
}

int Computer::pureMCTS(connect4Board board) {
   vector<int> legal_moves = board.legalMoves();
   vector<vector<int>> playoutResults;
   int i, j;
   srand(time(NULL));
   for(i=0;i<legal_moves.size();i++) {
        vector<int> moveResults = {0, 0, 0, legal_moves[i]};
        for(j=0;j<random_playouts;j++) {
            int result = randomPlayout(board, legal_moves[i]);
            moveResults[result] += 1;
        }
        playoutResults.push_back(moveResults);
   }

  for(i=0;i<playoutResults.size();i++) {
      for(j=0;j<playoutResults[i].size();j++) {
          cout << playoutResults[i][j] << "  ";
      }
      cout << "\n";
  }

   int maximum = 0;
   for(i=0;i<playoutResults.size();i++) {
        if(playoutResults[i][0] + playoutResults[i][2] > playoutResults[maximum][0] + playoutResults[maximum][2])
            maximum = i;
   }

   int index = playoutResults[maximum][3];   
   return index; 
}

int Computer::randomPlayout(connect4Board board, int index) {
    board.setIndex(index);
    char init_turn = board.getTurn();
    vector<int> legal_moves = board.legalMoves();
    //srand(time(NULL));
    while(true) {
        if(board.checkWin() && board.getTurn() == init_turn) {
           // cout << board; 
            return 0;
        }
        else if(board.checkWin() && board.getTurn() != init_turn) {
           // cout << board; 
            return 1;
        }
        else if(board.isFull()) {
           // cout << board; 
            return 2;
        }
        
        board.swapTurn();
        int random = rand() % legal_moves.size();
        board.setIndex(legal_moves[random]);
        legal_moves = board.legalMoves();
    }
}

int Computer::heuristicMCTS(connect4Board board) {
    vector<int> legal_moves = board.legalMoves();
    vector<vector<int>> playoutResults;
    int i, j, curr;
    
    for(i=0;i<legal_moves.size();i++) {
        if(canWin(board, legal_moves[i])) 
            return legal_moves[i];
    }
    
    for(i=0;i<legal_moves.size();i++) {
        if(willLose(board, legal_moves[i]))
            return legal_moves[i];
    }
    
    for(i=0;i<legal_moves.size();i++) {
        vector<int> moveResults = {0, 0, 0, legal_moves[i]};
        for(j=0;j<random_playouts;j++) {
            int result = educatedPlayout(board, legal_moves[i]);
            moveResults[result] += 1;
        }
        playoutResults.push_back(moveResults);
    }

    int maximum = 0;
    for(i=0;i<playoutResults.size();i++) {
        if(playoutResults[i][0] + playoutResults[i][2] > playoutResults[maximum][0] + playoutResults[maximum][2])
            maximum = i;
    }

    int index = playoutResults[maximum][3];
    return index;

}

int Computer::educatedPlayout(connect4Board board, int index) {
    board.setIndex(index);
    char init_turn = board.getTurn();
    vector<int> legal_moves = board.legalMoves();
    while(true) {
        if(board.checkWin() && board.getTurn() == init_turn) {
            return 0;
        }
        else if(board.checkWin() && board.getTurn() != init_turn) { 
            return 1;
        }
        else if(board.isFull()) {
            return 2;
        }
        
        board.swapTurn();
        int random = getGoodMove(board);
        board.setIndex(random);
        legal_moves = board.legalMoves();
    }
}

int Computer::getGoodMove(connect4Board board) {
    vector<int> legal_moves = board.legalMoves();
    if (legal_moves.size() == 1) {
      return legal_moves.front();
    }
    int i;
    double curr;
    srand(time(NULL));
    vector<int> best_moves;
    double lowest = 10000000; 
    long lowestIndex;
    for(i=0;i<legal_moves.size();i++) {
        curr = heuristic_(board, legal_moves[i]);
        if(curr < lowest) {
            lowest = curr;
            lowestIndex = i;
        }
    }
    legal_moves.erase(legal_moves.begin() + lowestIndex);
    int random = rand() % legal_moves.size();
    return legal_moves[random];
}

bool Computer::canWin(connect4Board board, int index) {
     board.setIndex(index);
     return board.checkWin();
}

bool Computer::willLose(connect4Board board, int index) {
    board.swapTurn();
    board.setIndex(index);
    return board.checkWin();
}

double Computer::heuristic_(connect4Board board, int index) {
    board.setIndex(index);
    int good3s = board.getThrees();
    int good2s = board.getTwos();
    double goodSum = (good3s);
    board.swapTurn();
    int bad3s = board.getThrees();
    int bad2s = board.getTwos();
    double badSum = (bad3s);
    return goodSum - badSum;
}