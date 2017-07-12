#ifndef DEF_SNAKE
#define DEF_SNAKE

#include <iostream>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "CONST.h"
#include "math.h"

using namespace sf;
using namespace std;



class Snake
{
    public:
      Snake(RenderWindow* window);
      ~Snake();
      int add(Position a,int direction);
      int add(int direction);
      void remove();
      bool contains(Position a);
      Position GetPos(int a);
      int getSize();
      void set();
      /*
      bool contains(Position a);
      int getSize();
      Position GetPos(int a);
      Position getNewPos();
      */
      void draw();

    private:
      Snek *Pos;
      int number;
      int size;
      int first;
      int last;
      Texture SerpentTexture;
      Sprite corps;
      RenderWindow* window;

};

#endif
