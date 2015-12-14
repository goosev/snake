#include "snake.h"

Point::Point(int _x, int _y, char* _sym)
{
  x=_x;
  y=_y;
  sym=_sym;
}

Point::Point()
{
  x=0;
  y=0;
  sym=NULL;
}

void Point::Draw()
{
  move(y,x);
  printw(sym);
}

