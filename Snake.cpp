#include "Snake.h"


using namespace sf;
using namespace std;

Snake::Snake(RenderWindow *window)
{
  number = 500;
  Pos = (Snek*) malloc(sizeof(Snek) * number);
  size = 0;
  first = -1;
  last = 0;

  this->window = window;
  if(!SerpentTexture.loadFromFile("img/snake.png"))
  {
    cout << "snake not found" << endl;
  }

  corps.setTexture(SerpentTexture);

}

Snake::~Snake()
{
  free(Pos);
}

int Snake::add(Position a, int direction)
{
  bool cont = this-> contains(a);
  size ++;
  first ++;
  first = first % number;
  /*
  if(a.x >= width / size_Snake)
    a.x = 0;
  if(a.x < 0)
    a.x = width/ size_Snake - 1;
  if(a.y >= height/ size_Snake)
    a.y = 0;
  if(a.y < 0)
    a.y = height/ size_Snake - 1;
*/
  Pos[first].pos = a;
  Pos[first].direction = direction;
  return cont;
}

int Snake::add(int direction)
{
  Position old = Pos[first].pos;
  int direction_old = Pos[first].direction;

if((direction + direction_old) %2 == 0)
  direction = direction_old;

Pos[first].direction = Table[direction_old][direction];

  switch (direction) {
    case 0:
      old.x --;
    break;
    case 1:
      old.y --;
    break;
    case 2:
      old.x++;
    break;
    case 3:
      old.y ++;
    break;
  }
  return this->add(old,direction);

}

void Snake::remove()
{
  size --;
  last ++;
  last = last % number;
}

void Snake::draw()
{

  for(int i = 0; i < size ; i++)
  {
    if(i ==0)
    {
      if (Pos[last].direction > 3)
      corps.setTextureRect(IntRect(50,(Pos[(last)].direction+1)%4 *25,25,25));

      else if (Pos[last].direction < 0)
      {
        corps.setTextureRect(IntRect(50,(abs(Pos[(last)].direction+2)%4) *25,25,25));
      }


      else
      corps.setTextureRect(IntRect(50,(Pos[(last)%number].direction)%4 *25,25,25));

      corps.setOrigin(-Pos[last].pos.x*size_Snake,-Pos[last].pos.y*size_Snake);
      window->draw(corps);
    }
    else if(i == size -1)
    {
      corps.setTextureRect(IntRect(0,Pos[(last+i)%number].direction*25,25,25));
      corps.setOrigin(-Pos[(last+i)%number].pos.x*size_Snake,-Pos[(last+i)%number].pos.y*size_Snake);
      window->draw(corps);
    }
    else
    {
      if(abs(Pos[(last+i)%number].direction) > 3)
      {
        corps.setTextureRect(IntRect(75,(abs(Pos[(last+i)%number].direction))%4 *25,25,25));
      }
      else
      {
        corps.setTextureRect(IntRect(25,Pos[(last+i)%number].direction*25,25,25));
      }
      corps.setOrigin(-Pos[(last+i)%number].pos.x*size_Snake,-Pos[(last+i)%number].pos.y*size_Snake);
      window->draw(corps);
    }
  }
}

bool Snake::contains(Position a)
{
    for(int i =0; i < size;i++)
    {
      Position b = this->GetPos(i);
      if(a.x == b.x && a.y == b.y )
        return true;
    }
    return false;
}

Position Snake::GetPos(int a)
{
  a = last + a;
  a = a % number;
  return Pos[a].pos;
}

int Snake::getSize()
{
  return size;
}

void  Snake::set()
{
  for(int i =0;i < size ;)
  {
    this->remove();
  }
  Position kek;
  kek.x = 22;
  kek.y = 19;
  this->add(kek,2);
  kek.x = 23;
  this->add(kek,2);
  kek.x = 24;
  this->add(kek,2);
}
