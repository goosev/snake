#include <iostream>
#include <ncurses.h>
#include <list>
#include "snake.h"

int main(int argc, char *argv[])
{

  Point p1=Point(1,3,"*");
  Point p2=Point(4,5,"#");
  
  std::list<Point> pList;
  pList.push_back (p1);
  pList.push_back (p2);
  
  
  initscr();
  curs_set(0);

  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
    it->Draw();
  
  HorizontalLine *upLine = new HorizontalLine(0,78,0,"+");
  VerticalLine *leftLine = new VerticalLine(0,24,0,"+");
  upLine->Draw();
  leftLine->Draw();

  refresh();
  getch();
  endwin();

  return 0;
}