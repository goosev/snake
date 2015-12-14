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

HorizontalLine::HorizontalLine(int xLeft, int xRight, int y, char* sym)
{
  for(int x = xLeft; x<=xRight; x++)
  {
    Point p=Point(x, y, sym);
    pList.push_back (p);
  }
}
void HorizontalLine::Draw()
{
  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
      it->Draw();
}

VerticalLine::VerticalLine(int yUp, int yDown, int x, char* sym)
{
  for(int y = yUp; y<=yDown; y++)
  {
    Point p=Point(x, y, sym);
    pList.push_back (p);
  }

}
void VerticalLine::Draw()
{
  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
      it->Draw();
}
