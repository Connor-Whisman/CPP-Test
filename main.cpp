#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define SEG_WIDTH 200
#define SEG_HEIGHT 400

void decode(bool A, bool B, bool C, bool D)
{
    bool a, b, c, d, e, f, g = 0;

    a = ((B && D) || (!B && !D)) || (A || C);
    b = ((C && D) || (!C && !D)) || !B;
    c = (B || !C) || D;
    d = ((!B && !D) || (C && !D) || (!B && C)) || ((B && !C && D) || A);
    e = (C && !D) || (!B && !D);
    f = (B && !C) || (B && !D) || (!C && !D) || A;
    g = ((C && !D) || (B && !C)) || ((!B && C) || A);

    cout << a << b << c << d << e << f << g << "\n";
}



int main()
{
    decode(0,0,0,1);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "7 Segment Decoder");

    sf::RectangleShape segDisplay(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    const int segPosX = WINDOW_WIDTH / 2 - SEG_WIDTH / 2 + 350;
    const int segPosY = WINDOW_HEIGHT / 2 - SEG_HEIGHT / 2;
    segDisplay.setFillColor(sf::Color::Black);
    segDisplay.setPosition(segPosX, segPosY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(segDisplay);
        window.display();
    }
    return 0;
}

