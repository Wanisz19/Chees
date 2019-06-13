#include "ChickenHome.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <time.h>
#include <windows.h>


ChickenHome::ChickenHome()
{

for(int i=0; i<8; i++)

    {   tabEgg[i].haslife=0;
        tabEgg[i].existing=0;
        tabEgg[i].eggX=0;
        tabEgg[i].eggY=0;
    }



    eggs=0;
    score=0;
    CanMove=2;


}


void ChickenHome::Refresh()
{

     for(int idy=0;idy<2;idy++)
    {
        for(int idx=0;idx<12;idx++)
        {

            tab[idx][idy].egg_alive=0;
            tab[idx][idy].wolf_alive=0;


        }

    }


    for(int i=0; i<8; i++)
    {
        if(tabEgg[i].existing==1)
        {

            tab[tabEgg[i].eggX][tabEgg[i].eggY].egg_alive=1;


        }



    }


}

void ChickenHome::debug_display() const
{
    for(int idy=0;idy<2;idy++)
    {
        for(int idx=0;idx<12;idx++)
        {
            cout<<"|";
            if(tab[idx][idy].egg_alive==1&&tab[idx][idy].wolf_alive==0)
            {
            cout<<"EGG";
            }
             else if (tab[idx][idy].wolf_alive==1)
            {
            cout<<"WOL";

            }
           else  if(tab[idx][idy].wolf_alive==0 &&tab[idx][idy].wolf_alive==0)
            {
            cout<<"___";
            }
        }
            cout<<"|";

           cout<<endl;
        }

    }





int ChickenHome::CheckNumberOfeggs()
{
     for(int idy=0;idy<2;idy++)
    {
        for(int idx=0;idx<12;idx++)
        {
            if(tab[idx][idy].egg_alive==1)
            {
                eggs+=1;
            }


        }

    }

    return eggs;

}

void ChickenHome::BorningEggs()
{

     if(score<=5) // >>>>>>>>
        {
        tabEgg[0].existing=1;
        }
        if(score>5 && score<=10) // >>>>>>>>
        {
        tabEgg[1].existing=1;
        tabEgg[2].existing=1;
        }
        if(score>10 && score<=15) // >>>>>>>>          /// DO WYREGULOWANIA XD
        {
        tabEgg[3].existing=1;
        tabEgg[4].existing=1;
        }



}
void ChickenHome::generatePosition()
{

    int spotofEgg;


    spotofEgg=rand()%(4)+1;


    if(spotofEgg==1)
            {
                posX=0;
                posY=0;
            }

        if(spotofEgg==2)
            {
                posX=0;
                posY=1;
            }

        if(spotofEgg==3)
            {
                posX=11;
                posY=0;
            }

        if(spotofEgg==4)
            {
                posX=11;
                posY=1;
            }

    }



void ChickenHome::Spawneggs()
{

    BorningEggs();



for(int i=0; i<8; i++)
    {
      //  if(CanMove%2==0)
       // {
        generatePosition();


        if(tabEgg[i].existing==1 )
        {
            if(tabEgg[i].haslife!=1)
            {

            tabEgg[i].eggX=posX;
            tabEgg[i].eggY=posY;
            tabEgg[i].haslife=1;
            }

        }

    }








}

void ChickenHome::Pusheggs()
{

for(int x=0; x<8; x++)
    {
            if(tabEgg[x].existing==1)
            {

        if(tabEgg[x].eggX<5)
            {
            tabEgg[x].eggX++;

            }
        else if(tabEgg[x].eggX>6)
            {
            tabEgg[x].eggX--;

            }

            }
            //CanMove+=1;

    }

}

void ChickenHome::CatchEgg()
{
    for(int idy=0;idy<2;idy++)
    {
        for(int idx=0;idx<12;idx++)
        {

        if(tab[idx][idy].egg_alive==1&&tab[idx][idy].wolf_alive==1)
        {
            score+=1;
            tab[idx][idy].egg_alive=0;

        }


        }

    }

}

bool ChickenHome::CollisionEggs()
{

    if(tab[0][0].egg_alive!=tab[0][1].egg_alive!=tab[11][0].egg_alive!=tab[11][1].egg_alive)
    {
        return 1;
    }
    else
        return 0;
}


void ChickenHome::game()
{

    for(;;)
    {
    Spawneggs();
    Refresh();
    debug_display();
    Pusheggs();
    Sleep(1000);

    }
}


