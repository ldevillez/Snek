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
  if(!pom.loadFromFile("img/pomme.png"))
  {
    cout << "snake not found" << endl;
  }
  apple.setTexture(pom);
  direction = 2;
  finished = 0;
  nbObstacle = 0;
  this->makeObstacle();
  snake = new Snake(window,1);
  snake2 = new Snake(window,2);
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
      direction2 = 0;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      direction2 = 1;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      direction2 = 2;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      direction2 = 3;

  return 1-sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

void Game::create(int player)
{
  this->player = player;
  finished = 0;
  snake->set(1);
  direction = 2;
  score = 0;
  if(player == 2)
  {
    snake2->set(2);
    direction2 = 0;
    score2 = 0;
  }
  Pomme = this->getNewPomme();
  apple.setOrigin(-Pomme.x *25,-Pomme.y *25);
}

int Game::update()
{
  if(player == 1)
  {
    Position a = snake->tryAdd(direction);
    if(posEqual(a,Pomme))
    {
      score ++;
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
  else
  {
    Position a = snake->tryAdd(direction);
    Position b = snake2->tryAdd(direction2);
    if(posEqual(a,Pomme))
    {
      score++;
      snake->add(direction);
      Pomme = this->getNewPomme();
      apple.setOrigin(-Pomme.x *25,-Pomme.y *25);
    }
    else if (posEqual(b,Pomme))
    {
      score2++;
      snake2->add(direction2);
      Pomme = this->getNewPomme();
      apple.setOrigin(-Pomme.x *25,-Pomme.y *25);
    }
    else if(snake->contains(b)||snake2->contains(a)||posEqual(a,b))
    {
      finished = 1;
    }
    else
    {
      int i = snake->add(direction);
      i += snake2->add(direction2);
      for(int j = 0; j < nbObstacle; j++)
      {
        i += snake->contains(obstacle[j]);
        i += snake2->contains(obstacle[j]);
      }

      if (i > 0)
        finished = 1;

      snake->remove();
      snake2->remove();
    }
    return snake->getSize();
  }
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
  if (player == 2)
    snake2->draw();
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
  bool Snek2Contain = false;
  do
  {
    a = snake->getNewPos();
    if(player == 2)
      Snek2Contain = snake2->contains(a);

  } while(isObstacle(a) || Snek2Contain);
  return a;
}

void Game::showScore()
{
  Clock clock;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  Text sco("score",font,30);
  sco.setStyle(sf::Text::Bold);
  //score.setColor(sf::Color::Red);
  sco.move(500,500);

  if(player == 1)
  sco.setString("score: " +  to_string(score));
  else
  sco.setString("score 1: " +  to_string(score) +"\n score 2: " + to_string(score2));
  window->draw(sco);
  window->display();
  while(clock.getElapsedTime().asSeconds() < 3) {

  }
}
