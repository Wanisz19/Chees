#ifndef CHICKENHOME_H
#define CHICKENHOME_H
using namespace std;
struct State
{

    bool wolf_alive, egg_alive;
};

struct PositionEgg
{
    int eggX, eggY;
    bool existing;
    bool haslife;

};

struct PositionWolf
{

    int wolfX, wolfY;
};




class ChickenHome
{

State tab[20][20];
PositionEgg tabEgg[12];
PositionWolf tabWolf;
int score;
int eggs;
int posX;
int posY;
int CanMove;

public:

ChickenHome();
void Refresh();
void debug_display() const;
int CheckNumberOfeggs();
void BorningEggs();
void generatePosition();
void Spawneggs();
void Pusheggs();
void CatchEgg();
bool CollisionEggs();
void game();



};


#endif
