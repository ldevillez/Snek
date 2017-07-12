#ifndef DEF_CONST
#define DEF_CONST


  const int width = 1200;
  const int height = 1000;
  const int offset = 25;
  const int size_Snake = 25;
  const int nHeight = height / 25;
  const int nWidth =  width / 25;

  int const Table[4][4] = {{0,4,0,-5},{-6,1,5,1},{2,-7,2,6},{7,3,-4,3}};

  struct Position
  {
    int x;
    int y;
  };
  struct Snek
  {
    Position pos;
    int direction;
  };

#endif
