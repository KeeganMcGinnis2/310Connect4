#include "board.h"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

connect4Board::connect4Board() {
    int i;
    for(i=0;i<42;i++)
        board.push_back(' ');
    turn = 'R';
}

connect4Board::connect4Board(vector<char> b) {
    board = b;
}

vector<char> connect4Board::getBoard() {
    return board;
}

void connect4Board::swapTurn() {
    if(turn == 'R') {
        turn = 'Y';
    } else {
        turn = 'R';
    }
}

char connect4Board::getTurn() {
    return turn;
}

bool connect4Board::columnFull(int col) {
    int i;
    return (board[col+34] != ' ');
}

int connect4Board::columnSize(int col) {
    int size = 0;
    for (int i = 0; i < 6; i++) {
      if (board[col + i*7 - 1] != ' ')
        size ++;
      else {
        return size;
      }
    }
    return size;
}


vector<int> connect4Board::legalMoves() {
    vector<int> legal_moves;
    int i;
    for(i=1;i<8;i++) {
        if(!columnFull(i)) {
            legal_moves.push_back(i);
        }
    }
    return legal_moves;
}

bool connect4Board::isFull() {
    int i;
    for(i=1;i<8;i++){
        if(!columnFull(i)) {
            return false;
        }
    }
    return true;
}

void connect4Board::setIndex(const int col) {
    int i;
    for(i=col-1;i<42;i+=7) {
        if(board[i] == ' ') {
            board[i] = turn;
            break;
        }
    }
}

bool connect4Board::checkWin() {
    return checkHorizontal() || checkVertical() || checkDiagonal();
}

bool connect4Board::checkHorizontal() {
    int i, j;
    for(i=0;i<36;i+=7) {
        for(j=i;j<i+4;j++) {
            if(board[j] == turn && board[j+1] == turn && board[j+2] == turn && board[j+3] == turn)
                return true;
        }
    }
    return false;
}

bool connect4Board::checkVertical() {
    int i;
    for(i=0;i<21;i++) {
        if(board[i] == turn && board[i+7] == turn && board[i+14] == turn && board[i+21] == turn)
            return true;
    }
    return false;
}

bool connect4Board::checkDiagonal() {
    int i, j;
    //check right diagonals
    for(i=0;i<15;i+=7) {
        for(j=i;j<i+4;j++) {
            if(board[j] == turn && board[j+8] == turn && board[j+16] == turn && board[j+24] == turn)
                return true;
        }
    }

    //check left diagonals
    for(i=3;i<18;i+=7) {
        for(j=i;j<i+4;j++) {
            if(board[j] == turn && board[j+6] == turn && board[j+12] == turn && board[j+18] == turn)
                return true;
        }
    }
    
    return false;
}

int connect4Board::getThrees() {
    int threes;
    int i, j;
    //horizontal
    for(i=0;i<36;i+=7) {
        for(j=i;j<i+5;j++) {
            if(board[j] == turn && board[j+1] == turn && board[j+2] == turn && board[j+3] == ' ')
                threes++;
        }
    }

    //vertical
    for(i=0;i<28;i++) {
        if(board[i] == turn && board[i+7] == turn && board[i+14] == turn && board[i+21] == ' ')
            threes++;
    }

    //check right diagonals
    for(i=0;i<22;i+=7) {
        for(j=i;j<i+5;j++) {
            if(board[j] == turn && board[j+8] == turn && board[j+16] == turn && board[j+24] == ' ')
                threes++;
        }
    }

    //check left diagonals
    for(i=2;i<25;i+=7) {
        for(j=i;j<i+4;j++) {
            if(board[j] == turn && board[j+6] == turn && board[j+12] == turn && board[j+18] == ' ')
                threes++;
        }
    }

    return threes;
}

int connect4Board::getTwos() {
    int threes;
    int i, j;
    //horizontal
    for(i=0;i<36;i+=7) {
        for(j=i;j<i+5;j++) {
            if(board[j] == turn && board[j+1] == turn && board[j+2] == ' ' && board[j+3] == ' ')
                threes++;
        }
    }

    //vertical
    for(i=0;i<28;i++) {
        if(board[i] == turn && board[i+7] == turn && board[i+14] == ' ' && board[i+21] == ' ')
            threes++;
    }

    //check right diagonals
    for(i=0;i<22;i+=7) {
        for(j=i;j<i+5;j++) {
            if(board[j] == turn && board[j+8] == turn && board[j+16] == ' ' && board[j+24] == ' ')
                threes++;
        }
    }

    //check left diagonals
    for(i=2;i<25;i+=7) {
        for(j=i;j<i+4;j++) {
            if(board[j] == turn && board[j+6] == turn && board[j+12] == ' ' && board[j+18] == ' ')
                threes++;
        }
    }

    return threes;
}

ostream &operator << (ostream &output, const connect4Board &game_board){
    output << "   1   2   3   4   5   6   7\n";
    output << " -----------------------------\n";
    int i, j;
    for(i=35;i>=0;i-=7) {
        output << " |";
        for(j=i;j<i+7;j++) {
            output << " ";
            output << game_board.board[j];
            output << " |";
        }
        output << "\n -----------------------------\n";
    }
    return output;
}