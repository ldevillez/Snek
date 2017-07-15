#ifndef DEF_SNAKE
#define DEF_SNAKE

#include <iostream>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "CONST.h"
#include "math.h"
#include "fun.h"

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
      Position getNewPos();
      void draw();
      Position tryAdd(int direction);

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
