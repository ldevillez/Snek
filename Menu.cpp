#include "Menu.hpp"

using namespace sf;
using namespace std;

Menu::Menu(RenderWindow* window)
{
  this->window = window;
  if(!Fond.loadFromFile("img/fond.png"))
  {
    cout << "Fond not found" << endl;
  }
  if(!Buttons.loadFromFile("img/button.png"))
  {
    cout << "button not found" << endl;
  }
  Background.setTexture(Fond);
  Button1.setTexture(Buttons);
  Button1.setTextureRect(IntRect(0,0,599,149));
  Button1.move(Vector2f(299,350));
  Button2.setTexture(Buttons);
  Button2.setTextureRect(IntRect(0,149,599,149));
  Button2.move(Vector2f(299,499));
  Button3.setTexture(Buttons);
  Button3.setTextureRect(IntRect(0,299,599,149));
  Button3.move(Vector2f(299,648));
}

Menu::~Menu()
{

}

int Menu::getEvent()
{
  Event event;
  int ret = 0;
  window->pollEvent(event);

  Vector2i localPosition = sf::Mouse::getPosition(*window);
  if((299 <= localPosition.x && localPosition.x <=899) && (350<=localPosition.y&&localPosition.y <=499))
  {
    Button1.setTextureRect(IntRect(600,0,599,149));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      ret = 1;
  }
  else
  {
    Button1.setTextureRect(IntRect(0,0,599,149));
  }
  if((299 <= localPosition.x && localPosition.x <=899) && (500<=localPosition.y&&localPosition.y <=659))
  {
    Button2.setTextureRect(IntRect(600,149,599,149));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      ret = 3;
  }
  else
  {
    Button2.setTextureRect(IntRect(0,149,599,149));
  }
  if((299 <= localPosition.x && localPosition.x <=899) && (650<=localPosition.y&&localPosition.y <=799))
  {
    Button3.setTextureRect(IntRect(600,299,599,149));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      window->close();
  }
  else
  {
    Button3.setTextureRect(IntRect(0,299,599,149));
  }

  return ret;
}

void Menu::draw()
{
  window->draw(Background);
  window->draw(Button1);
  window->draw(Button2);
  window->draw(Button3);
}
