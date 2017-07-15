#include "fun.h"
using namespace std;

int RandomInt(int a, int b)
{
  std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(a,b);
  return dis(gen);
}

int posEqual(Position a, Position b)
{
  return a.x == b.x && b.y == a.y;
}
