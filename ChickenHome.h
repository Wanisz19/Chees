#ifndef CHICKENHOME_H
#define CHICKENHOME_H
#include <SFML/Graphics.hpp>
using namespace std;

enum StateOfGame{RUNNING, LOSE};
enum Stage{SLOW, NORMAL, FAST, FASTER, GOD};
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

StateOfGame statt;
State tab[20][20];
PositionEgg tabEgg[12];
PositionWolf tabWolf;
int score;
int eggs;
int posX;
int posY;
double speed;
bool goodEgg;
sf::Event event;
sf::Time times;
sf::Clock clocks;

int CanMove;

public:

ChickenHome();
void Refresh();
void debug_display() const;
int CheckNumberOfeggs();
void BorningEggs();
int isEggs();
void generatePosition();
void Spawneggs();
void Pusheggs();
void CatchEgg();
bool CollisionEggs();
int stateOfField(int idx, int idy);
void handleEvent(sf::Event &event);
int Getscore();
void maxPosition();
void game();
bool GameOver();



};


#endif
