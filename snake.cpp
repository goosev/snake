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

/*
Point::Point(Point &p)
{
  x=p.x;
  y=p.y;
  sym=p.sum;
}
*/

void Point::Move(int offset, Direction direction)
{
  switch(direction){ 
    case RIGHT:
    x=x+offset;
    break;
    case LEFT:
    x=x-offset;
    break;
    case UP:
    y=y+offset;
    break;
    case DOWN:
    y=y-offset;
    break;
  }
}

void Point::Draw()
{
  move(y,x);
  printw(sym);
}

HorizontalLine::HorizontalLine(int xLeft, int xRight, int y, char* sym):Figure()
{
  for(int x = xLeft; x<=xRight; x++)
  {
    Point p=Point(x, y, sym);
    pList.push_back (p);
  }
}

VerticalLine::VerticalLine(int yUp, int yDown, int x, char* sym):Figure()
{
  for(int y = yUp; y<=yDown; y++)
  {
    Point p=Point(x, y, sym);
    pList.push_back (p);
  }

}

Figure::Figure()
{
  ;
}

void Figure::Draw()
{
  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
      it->Draw();
}

Snake::Snake(Point tail, int lenght, Direction direction):Figure()
{
  for(int i = 0; i<lenght; i++)
  {
    Point p=tail;
    p.Move(i, direction);
    pList.push_back (p);
  }
}
