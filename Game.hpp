#ifndef DEF_GAME
#define DEF_GAME

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"

using namespace sf;
using namespace std;


class Game
{
    public:
      Game(RenderWindow* window);
      ~Game();
      int getEvent();
      void draw();
      void create();
      int update();
      int isNotFinished();
      void makeObstacle();
      Position getNewPomme();
      int isObstacle(Position a);


    private:
    Texture Fond, pom;
    Sprite Background,apple;
    RenderWindow* window;
    Snake* snake;
    int direction;
    int finished;
    Position obstacle[500];
    int nbObstacle;
    Position Pomme;
};

#endif
