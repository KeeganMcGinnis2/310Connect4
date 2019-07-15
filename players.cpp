#include "players.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

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

int Human::chooseMove() {
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

/*int Computer::chooseMove() {
    return pureMCTS();
}

int Computer::pureMCTS() {

}

vector<int> Computer::randomPlayout() {

}*/