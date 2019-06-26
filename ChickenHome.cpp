#include "ChickenHome.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <SFML/Graphics.hpp>

ChickenHome::ChickenHome()
{
    lifes=3;
    steps=0;
    speed=0.9;
    statt==RUNNING;
    for(int i=0; i<8; i++)

    {
        tabEgg[i].haslife=0;
        tabEgg[i].existing=0;
        tabEgg[i].eggX=0;
        tabEgg[i].eggY=0;
        tabEgg[i].distanceOfEgg=0;
    }

    tabWolf.wolfX=5;
    tabWolf.wolfY=0;
    eggs=0;
    score=0;
    Refresh();

}

void ChickenHome::Refresh()
{
    for(int idy=0; idy<2; idy++)
    {
        for(int idx=0; idx<12; idx++)
        {
            tab[idx][idy].egg_alive=0;
            tab[idx][idy].wolf_alive=0;
        }
    }

    tab[tabWolf.wolfX][tabWolf.wolfY].wolf_alive=1;

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
    for(int idy=0; idy<2; idy++)
    {
        for(int idx=0; idx<12; idx++)
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
    for(int idy=0; idy<2; idy++)
    {
        for(int idx=0; idx<12; idx++)
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
    if(lifes>0)
    {
        tabEgg[0].existing=1;
        if(steps>6)
        {
            speed=0.8;
            tabEgg[0].existing=1;
            tabEgg[1].existing=1;
        }
        if(steps>30)
        {
            tabEgg[2].existing=1;
        }
        speed=0.7;

        if(steps>45)
        {
            tabEgg[3].existing=1;
        }
        if(steps>70)
        {
            speed=0.6;
            tabEgg[4].existing=1;
        }
        if(steps>90)
        {
            speed=0.5;
            tabEgg[5].existing=1;
        }
        if(steps>120)
        {
            speed=0.45;
        }
    }
}


int ChickenHome::isEggs()
{
    int numberEggs=0;
    if(tab[0][0].egg_alive==1)
    {
        numberEggs++;
    }
    if(tab[0][1].egg_alive==1)
    {
        numberEggs++;
    }
    if(tab[11][0].egg_alive==1)
    {
        numberEggs++;
    }
    if(tab[11][1].egg_alive==1)
    {
        numberEggs++;
    }
    return numberEggs;
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

    for(int i=0; i<8; i++)
    {
        if(tabEgg[i].existing==1 )
        {
            if(tabEgg[i].haslife!=1)
            {
                tabEgg[i].eggX=posX;
                tabEgg[i].eggY=posY;
                tabEgg[i].haslife=1;
                break;
            }
        }
    }
}



void ChickenHome::Spawneggs()
{
    BorningEggs();
    generatePosition();
}


void ChickenHome::Pusheggs()
{
    steps++;
    for(int x=0; x<8; x++)
    {
        if(tabEgg[x].existing==1 && tabEgg[x].haslife==1)
        {
            tabEgg[x].distanceOfEgg++;

            if(tabEgg[x].eggX<5)
            {
                tabEgg[x].eggX++;
            }
            if(tabEgg[x].eggX>6)
            {
                tabEgg[x].eggX--;
            }
        }
    }
}

void ChickenHome::CatchEgg()
{
    for(int idy=0; idy<2; idy++)
    {
        for(int idx=0; idx<12; idx++)
        {
            if(tab[idx][idy].egg_alive==1&&tab[idx][idy].wolf_alive==1)
            {
                score++;
                maxPosition();
            }
            else if(tab[idx][idy].egg_alive==1&&tab[idx][idy].wolf_alive==0)
            {
                maxPosition();
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

int ChickenHome::stateOfField(int idx, int idy)
{
    if(tab[idx][idy].egg_alive==1&&tab[idx][idy].wolf_alive==0)
    {
        return 'E';
    }
    else if (tab[idx][idy].wolf_alive==1)
    {
        return 'W';
    }
    else  if(tab[idx][idy].wolf_alive==0 &&tab[idx][idy].wolf_alive==0)
    {
        return '_';
    }
}


void ChickenHome::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::W)
        {
            if(tabWolf.wolfY==1 )
                tabWolf.wolfY--;
        }

        if (event.key.code == sf::Keyboard::S)
        {
            if(tabWolf.wolfY==0 )
                tabWolf.wolfY++;
        }

        if (event.key.code == sf::Keyboard::D)
        {
            if(tabWolf.wolfX==5 )
                tabWolf.wolfX++;
        }

        if (event.key.code == sf::Keyboard::A)
        {
            if(tabWolf.wolfX==6)
                tabWolf.wolfX--;
        }

        if(lifes<0)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                lifes=3;
                Refresh();
                score=0;
            }

        }
    }

}
int ChickenHome::Getscore()
{
    return score;
}

void ChickenHome::game()
{
    times = clocks.getElapsedTime();
    if (times.asSeconds() >=speed)
    {
        GameOver();
        Refresh();
        Spawneggs();
        CatchEgg();
        Refresh();
        Pusheggs();
        clocks.restart();
    }
}

void ChickenHome::maxPosition()
{
    for(int i=0; i<8; i++)
    {
        if(tabEgg[i].eggX==5 || tabEgg[i].eggX==6)
        {
            tabEgg[i].haslife=0;
        }
    }
}

bool ChickenHome::GameOver()
{
    if((tab[5][0].egg_alive==1&&tab[5][0].wolf_alive==0)||(tab[5][1].egg_alive==1&&tab[5][1].wolf_alive==0)
            ||(tab[6][0].egg_alive==1&&tab[6][0].wolf_alive==0)||(tab[6][1].egg_alive==1&&tab[6][1].wolf_alive==0))
    {
        lifes--;


        if(lifes<0)
        {
            tabEgg[0].existing=0;
            tabEgg[1].existing=0;
            tabEgg[2].existing=0;
            tabEgg[3].existing=0;
            tabEgg[4].existing=0;
            tabEgg[5].existing=0;
            tabEgg[1].haslife=0;
            tabEgg[2].haslife=0;
            tabEgg[3].haslife=0;
            tabEgg[4].haslife=0;
            tabEgg[5].haslife=0;
            tabEgg[6].haslife=0;
            statt=LOSE;
            steps=0;
            setNullPos();
            Refresh();


        }
    }
    return 0;
}


int ChickenHome::howManyLifes()
{
    return lifes;
}

int ChickenHome::setNullPos()
{
    for(int i=0; i<8; i++)
    {
        tabEgg[i].eggX=0;
        tabEgg[i].eggY=0;
    }
    return 0;
}





