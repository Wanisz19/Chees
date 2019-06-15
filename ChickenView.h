#include <SFML/Graphics.hpp>
#include "ChickenHome.h"
#ifndef CHICKENVIEW_H
#define CHICKENVIEW_H


class ChickenView
{


    ChickenHome & Chicken;
    int x0, y0;
    int size_of_field;
    sf::Text text;
    sf::Font font;

public:
    ChickenView(int x0, int y0, int size_of_field, ChickenHome &ch);

    void draw(sf::RenderWindow &win);
    int getboardsize() const;
    int getx0() const;
    int gety0() const;
    void ButtonPressed (sf::Event &event);

};

#endif
