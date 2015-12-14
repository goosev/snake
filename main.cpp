#include <iostream>
#include <ncurses.h>
#include "snake.h"

int main(int argc, char *argv[])
{

  Point *p1=new Point(1,3,"*");
  Point *p2=new Point(4,5,"#");


  initscr();
  curs_set(0);
  p1->Draw();
  p2->Draw();
  refresh();
  getch();
  endwin();

  return 0;
}