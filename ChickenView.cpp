#include "ChickenHome.h"
#include "ChickenView.h"
#include <cstdlib>



ChickenView::ChickenView(int x0, int y0, int size_of_field, ChickenHome &ch):Chicken(ch)

{

this->x0=x0;
this->y0=y0;
this->size_of_field=size_of_field;
sf::Event event;



}



 void ChickenView::draw(sf::RenderWindow &win)
{
Chicken.game();


//if(font.loadFromFile("arial.ttf")
//text.setFont(font);


sf::RectangleShape rectangle(sf::Vector2f(80.f, 80.f)); // nie można wywołać fukcji getboardsize
rectangle.setOutlineThickness(1.f);
rectangle.setOutlineColor(sf::Color(23, 7, 249));



for(int y=0; y<2; y++)
{

for(int x=0; x<12; x++)
{

int wierszy;
int kolumnax;
kolumnax=x*size_of_field+x0;
wierszy=y*size_of_field+y0;

if(Chicken.stateOfField(x,y)=='E')
{
rectangle.setFillColor(sf::Color(249, 7, 225));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
}

else if(Chicken.stateOfField(x,y)=='W')
{
rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);

}

else if(Chicken.stateOfField(x,y)=='_')
{
rectangle.setFillColor(sf::Color(255,255,0));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);

}


/*if(board.getFieldInfo(x,y)=='_')
{
rectangle.setFillColor(sf::Color(249, 7, 225));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
}

else if(board.getFieldInfo(x,y)=='F')
{
text.setCharacterSize(size_of_field);
text.setFillColor(sf::Color::Yellow);

rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
text.setPosition(kolumnax,wierszy);
text.setString("F");
win.draw(text);
}

else if(board.isRevealed(x,y)==1 && board.ifhasMine(x,y)==0) //liczba min wokół pola
{
rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);


text.setCharacterSize(size_of_field/2);
text.setFillColor(sf::Color::Red);
text.setPosition(kolumnax,wierszy);

int liczba_min;

liczba_min= board.countMines(x,y);

switch(liczba_min)
{
case 1:
text.setString("1");
win.draw(text);
break;

case 2:
text.setString("2");
win.draw(text);
break;

case 3:
text.setString("3");
win.draw(text);
break;

case 4:
text.setString("4");
win.draw(text);
break;

case 5:
text.setString("5");
win.draw(text);
break;

case 6:
text.setString("6");
win.draw(text);
break;

case 7:
text.setString("7");
win.draw(text);
break;

case 8:
text.setString("8");
win.draw(text);
break;
}

}


else if(board.getFieldInfo(x,y)=='x' && board.ifhasMine(x,y)==1)
{
text.setCharacterSize(size_of_field);
text.setFillColor(sf::Color::Blue);

rectangle.setFillColor(sf::Color(64, 60, 60));
rectangle.setPosition(kolumnax,wierszy);
win.draw(rectangle);
text.setPosition(kolumnax,wierszy);
text.setString("M");
win.draw(text);


*/
}
}

}















