#ifndef DEF_MENU
#define DEF_MENU

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Menu
{
    public:
      Menu(RenderWindow window);
      ~Menu();


    private:
    Texture Fond,Buttons;
    Sprite Background;
    Sprite Button1,Button2,Button3;
    RenderWindow window;

};

#endif
