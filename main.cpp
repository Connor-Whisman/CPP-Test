#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define SEG_CONTAINER_WIDTH 200
#define SEG_CONTAINER_HEIGHT 400
#define SEG_WIDTH 20
#define SEG_HEIGHT 100

#define GREY 35, 35, 35

bool A = 1;
bool B = 1;
bool C = 1;
bool D = 1;
bool a, b, c, d, e, f, g = 0;


void decode()
{
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
    decode();


    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "7 Segment Decoder");

    const int segPosX = WINDOW_WIDTH / 2 - SEG_CONTAINER_WIDTH / 2 + 350;
    const int segPosY = WINDOW_HEIGHT / 2 - SEG_CONTAINER_HEIGHT / 2;

    // 7 SEGMENT CONTAINER
    sf::RectangleShape segDisplay(sf::Vector2f(SEG_CONTAINER_WIDTH, SEG_CONTAINER_HEIGHT));
    segDisplay.setFillColor(sf::Color::Black);
    segDisplay.setPosition(segPosX, segPosY);

    // SEGMENTS
    sf::RectangleShape segA(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segA.setFillColor(sf::Color::White);
    segA.setPosition(segPosX + SEG_HEIGHT / 2, segPosY + 50);
    segA.setRotation(-90);
    sf::RectangleShape segB(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segB.setFillColor(sf::Color::White);
    segB.setPosition(segPosX + SEG_CONTAINER_WIDTH - SEG_WIDTH - 25, segPosY + 75);
    sf::RectangleShape segC(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segC.setFillColor(sf::Color::White);
    segC.setPosition(segPosX + SEG_CONTAINER_WIDTH - SEG_WIDTH - 25, segPosY + SEG_CONTAINER_HEIGHT - SEG_HEIGHT - 75);
    sf::RectangleShape segD(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segD.setFillColor(sf::Color::White);
    segD.setPosition(segPosX + SEG_HEIGHT / 2, segPosY + SEG_CONTAINER_HEIGHT + SEG_WIDTH - 50);
    segD.setRotation(-90);
    sf::RectangleShape segE(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segE.setFillColor(sf::Color::White);
    segE.setPosition(segPosX + SEG_HEIGHT / 2 - 25, segPosY + SEG_CONTAINER_HEIGHT - SEG_HEIGHT - 75);
    sf::RectangleShape segF(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segF.setFillColor(sf::Color::White);
    segF.setPosition(segPosX + SEG_HEIGHT / 2 - 25, segPosY + 75);
    sf::RectangleShape segG(sf::Vector2f(SEG_WIDTH, SEG_HEIGHT));
    segG.setFillColor(sf::Color::White);
    segG.setPosition(segPosX + SEG_HEIGHT / 2, segPosY + SEG_CONTAINER_HEIGHT / 2 + SEG_WIDTH / 2);
    segG.setRotation(-90);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        a == 1 ? segA.setFillColor(sf::Color::Green) : segA.setFillColor(sf::Color(GREY));
        b == 1 ? segB.setFillColor(sf::Color::Green) : segB.setFillColor(sf::Color(GREY));
        c == 1 ? segC.setFillColor(sf::Color::Green) : segC.setFillColor(sf::Color(GREY));
        d == 1 ? segD.setFillColor(sf::Color::Green) : segD.setFillColor(sf::Color(GREY));
        e == 1 ? segE.setFillColor(sf::Color::Green) : segE.setFillColor(sf::Color(GREY));
        f == 1 ? segF.setFillColor(sf::Color::Green) : segF.setFillColor(sf::Color(GREY));
        g == 1 ? segG.setFillColor(sf::Color::Green) : segG.setFillColor(sf::Color(GREY));

        window.clear(sf::Color(150, 150, 150));
        window.draw(segDisplay);
        window.draw(segA);
        window.draw(segB);
        window.draw(segC);
        window.draw(segD);
        window.draw(segE);
        window.draw(segF);
        window.draw(segG);
        window.display();
    }

    return 0;
}

