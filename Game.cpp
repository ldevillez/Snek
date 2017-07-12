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
  direction = 2;
  finished = 0;
  nbObstacle = 0;
  this->makeObstacle();
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
  snake = new Snake(window);
  snake->set();
}

int Game::update()
{
  std::cout << nbObstacle << '\n';
  int i = snake->add(direction);
  for(int j = 0; j < nbObstacle; j++)
  {
    i += snake->contains(obstacle[j]);
  }

  if (i > 0)
    finished = 1;

  snake->remove();
  return snake->getSize();
}

int Game::isNotFinished()
{
  return 1-finished;
}

void Game::draw()
{
  window->draw(Background);
  snake->draw();
}

void Game::makeObstacle()
{

  for(int i = 0; i < nWidth+2;i++)
  {
    std::cout << nbObstacle << '\n';
    obstacle[nbObstacle].x = -1 + i;
    obstacle[nbObstacle].y = 0;
    nbObstacle ++;
    obstacle[nbObstacle].x = -1 + i;
    obstacle[nbObstacle].y = nHeight-1;
    nbObstacle ++;
  }
  for(int i = 0; i < nHeight;i++)
  {
    std::cout << nbObstacle << '\n';
    obstacle[nbObstacle].x = 0;
    obstacle[nbObstacle].y = -1+i;
    nbObstacle ++;
    obstacle[nbObstacle].x = nWidth -1;
    obstacle[nbObstacle].y = -1+i;
    nbObstacle ++;
  }
}
