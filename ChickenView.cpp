#include "ChickenHome.h"
#include "ChickenView.h"
#include <cstdlib>



ChickenView::ChickenView(int x0, int y0, int size_of_field, ChickenHome &ch):Chicken(ch)

{

this->poi=to_string(Chicken.Getscore());
this->x0=x0;
this->y0=y0;
this->size_of_field=size_of_field;
sf::Event event;


if (!font.loadFromFile("arial.ttf"))
{;}
if (!texture.loadFromFile("jajkox80.jpg")){}
if (!texture2.loadFromFile("BoxX80.jpg")){}
if (!texture3.loadFromFile("BlackBoxX80.jpg")){}
if (!texture4.loadFromFile("Heart.jpg")){}
if (!texture5.loadFromFile("wsad.png")){}


}



 void ChickenView::draw(sf::RenderWindow &win)
{
Chicken.game();




sf::RectangleShape rectangle(sf::Vector2f(80.f, 80.f)); // nie można wywołać fukcji getboardsize
rectangle.setOutlineThickness(1.f);
rectangle.setOutlineColor(sf::Color(23, 7, 249));



    poi=to_string(Chicken.Getscore());
    txt.setFont(font);
    txt.setString(poi);
    txt.setPosition(420, 200);
    txt.setFillColor(sf::Color::Green);
    txt.setCharacterSize(150);

    scor.setFont(font);
    scor.setString("Points:");
    scor.setPosition(30, 200);
    scor.setFillColor(sf::Color::Green);
    scor.setCharacterSize(150);

/////MAPA/////////
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
//rectangle.setFillColor(sf::Color(249, 7, 225));
//rectangle.setPosition(kolumnax,wierszy);
//win.draw(rectangle);

sf::Sprite sprite(texture);
  sprite.setPosition(kolumnax,wierszy);
      win.draw(sprite);


}

else if(Chicken.stateOfField(x,y)=='W')
{
sf::Sprite sprite(texture3);
  sprite.setPosition(kolumnax,wierszy);
      win.draw(sprite);

}

else if(Chicken.stateOfField(x,y)=='_')
{
//rectangle.setFillColor(sf::Color(255,255,0));
//rectangle.setPosition(kolumnax,wierszy);
//win.draw(rectangle);

sf::Sprite sprite(texture2);
  sprite.setPosition(kolumnax,wierszy);
      win.draw(sprite);

}

sf::Sprite sprite(texture5);
  sprite.setPosition(200,616);
      win.draw(sprite);


 win.draw(scor);
 win.draw(txt);
///////////////////////////////////////////

int kolumna=30;
for(int i=Chicken.howManyLifes(); i>=0; i--)
{
kolumna+=80;
sf::Sprite sprite(texture4);
  sprite.setPosition(kolumna,400);
      win.draw(sprite);



}
if(Chicken.howManyLifes()<0)
{
sf::RectangleShape rectangle(sf::Vector2f(1000.f, 1000.f)); // nie można wywołać fukcji getboardsize

txt.setPosition(670, 200);
scor.setPosition(280, 200);
                rectangle.setFillColor(sf::Color(0, 0, 0));
                rectangle.setPosition(0,0);
                win.draw(rectangle);
                 win.draw(scor);
                 win.draw(txt);
}



}
}

}















