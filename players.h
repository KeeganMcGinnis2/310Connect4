#include "board.h"
#include <string>
#include <vector>

using namespace std;

class Player {
    public:
        Player();

        Player(string n);

        void printName();

        virtual int chooseMove(connect4Board board) = 0;

    protected:
        string name;
};

class Human: public Player {
    public:
        Human(): Player() { };

        Human(string n): Player(n) { };

        int chooseMove(connect4Board board);
};

class Computer: public Player {
    public:
        Computer();

        Computer(string n, int r);

        int chooseMove(connect4Board board);

        int pureMCTS(connect4Board board);

        randomPlayout(connect4Board board, int index);

    private:
        int random_playouts;
};