#include <string>

using namespace std;

class Player {
    public:
        Player();

        Player(string n);

        void printName();

        virtual int chooseMove() = 0;

    protected:
        string name;
};

class Human: public Player {
    public:
        Human(): Player() { };

        Human(string n): Player(n) { };

        int chooseMove();
};

/*class Computer: public Player {
    public:
        Computer(): Player() { };

        Computer(string n): Player(n) { };

        int chooseMove();

        int pureMCTS();

        vector<int> randomPlayout();

        int hMCTS();
};*/