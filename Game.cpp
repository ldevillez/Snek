#include "Game.hpp"

using namespace sf;
using namespace std;

Game::Game(RenderWindow* window)
{
  this->window = window;
  if(!Fond.loadFromFile("img/fond.png"))
  {
    cout << "Fond not found" << endl;
  }
  Background.setTexture(Fond);
  if(!pom.loadFromFile("img/snake.png"))
  {
    cout << "snake not found" << endl;
  }
  apple.setTexture(pom);
  apple.setTextureRect(IntRect(0,100,25,25));
  direction = 2;
  finished = 0;
  nbObstacle = 0;
  this->makeObstacle();
  snake = new Snake(window);
}

Game::~Game()
{
}

int Game::getEvent()
{
  Event event;
  window->pollEvent(event);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    direction = 0;

  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    direction = 1;

  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    direction = 2;

  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    direction = 3;

  return 1-sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

void Game::create()
{
  finished = 0;
  snake->set();
  Pomme = this->getNewPomme();
  apple.setOrigin(-Pomme.x *25,-Pomme.y *25);
}

int Game::update()
{

  Position a = snake->tryAdd(direction);
  if(posEqual(a,Pomme))
  {
    snake->add(direction);
    Pomme = this->getNewPomme();
    apple.setOrigin(-Pomme.x *25,-Pomme.y *25);
  }
  else
  {
    int i = snake->add(direction);
    for(int j = 0; j < nbObstacle; j++)
    {
      i += snake->contains(obstacle[j]);
    }

    if (i > 0)
      finished = 1;

    snake->remove();
  }
  return snake->getSize();
}

int Game::isNotFinished()
{
  return 1-finished;
}

void Game::draw()
{
  window->draw(Background);
  window->draw(apple);
  snake->draw();
}

void Game::makeObstacle()
{

  for(int i = 0; i < nWidth+2;i++)
  {
    obstacle[nbObstacle].x = -1 + i;
    obstacle[nbObstacle].y = 0;
    nbObstacle ++;
    obstacle[nbObstacle].x = -1 + i;
    obstacle[nbObstacle].y = nHeight-1;
    nbObstacle ++;
  }
  for(int i = 0; i < nHeight;i++)
  {
    obstacle[nbObstacle].x = 0;
    obstacle[nbObstacle].y = -1+i;
    nbObstacle ++;
    obstacle[nbObstacle].x = nWidth -1;
    obstacle[nbObstacle].y = -1+i;
    nbObstacle ++;
  }
}

int Game::isObstacle(Position a)
{
  for(int i = 0; i < nbObstacle ; i++)
  {
    if(a.x == obstacle[i].x && a.y == obstacle[i].y)
      return 1;
  }
  return 0;
}

Position Game::getNewPomme()
{
  Position a;
  do
  {
    a = snake->getNewPos();
  } while(isObstacle(a));
  return a;
}
