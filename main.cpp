#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChickenHome.h"
#include "ChickenView.h"

using namespace std;



int main()
{
    srand(time(NULL));

    ChickenHome chicken;
    ChickenView view(10,30,80,chicken);

    //chicken.game();

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Wolf And Eggs");

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            chicken.handleEvent(event);
           //m.ButtonPressed(event);

        }


        window.clear();

        view.draw(window);


        window.display();
    }

    return 0;
}
