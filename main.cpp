#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChickenHome.h"

using namespace std;



int main()
{
    srand(time(NULL));

    ChickenHome chicken;
    chicken.game();
    //chicken.Spawneggs();
    //chicken.Refresh();
    //chicken.debug_display();
    //cout<< chicken.CollisionEggs();
   // cout << rand()%(4)+1 << endl;
    return 0;
}
