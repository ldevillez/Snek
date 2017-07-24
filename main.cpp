#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Game.hpp"
#include "CONST.h"
#include <string>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(sf::VideoMode(1200, 1000), "SFML works!");
    Menu menu(&window);
    Game game(&window);
    Clock clock;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    Text score("score",font,30);
    string sc = "score: ", leng;

    score.setStyle(sf::Text::Bold);
    //score.setColor(sf::Color::Red);
    score.move(500,500);

    Time actionTime = milliseconds(150);

    int choice = 0;
    while (window.isOpen())
    {
      switch (choice) {
        case 0:
          Event event;
          while (window.pollEvent(event) && choice == 0)
          {
              if (event.type == Event::Closed)
                  window.close();

              choice = menu.getEvent();
          }
          window.clear();
          menu.draw();
          window.display();
        break;
        case 1:
          game.create(1);

          while (game.getEvent()&&game.isNotFinished()) {
            if(operator<(actionTime,clock.getElapsedTime()))
            {
              clock.restart();
              leng = to_string(game.update());
              window.clear();
              game.draw();
              window.display();
            }
          }
          if(!game.isNotFinished())
          {
            choice = 2;
            clock.restart();
          }
          else
          choice = 0;
        break;

        case 2:
        score.setString(sc + leng);
          window.draw(score);
          window.display();
          while(clock.getElapsedTime().asSeconds() < 3) {

          }
          choice = 0;
        break;

        case 3:
        game.create(2);

          while (game.getEvent()&&game.isNotFinished()) {
            if(operator<(actionTime,clock.getElapsedTime()))
            {
              clock.restart();
              leng = to_string(game.update());
              window.clear();
              game.draw();
              window.display();
            }
          }
          if(!game.isNotFinished())
          {
            choice = 2;
            clock.restart();
          }
          else
          choice = 0;
        break;

        case 4:
        score.setString(sc + leng);
          window.draw(score);
          window.display();
          while(clock.getElapsedTime().asSeconds() < 3) {

          }
          choice = 0;
        break;


        default:
          window.close();
        break;
      }
    }

    return 0;
}
