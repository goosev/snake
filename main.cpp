#include <iostream>
#include <ncurses.h>
#include <list>
#include "snake.h"

int main(int argc, char *argv[])
{


  initscr();
  curs_set(0);

  HorizontalLine *upLine = new HorizontalLine(0,78,0,"+");
  HorizontalLine *downLine = new HorizontalLine(0,78,24,"+");
  VerticalLine *leftLine = new VerticalLine(0,24,0,"+");
  VerticalLine *rightLine = new VerticalLine(0,24,78,"+");
  upLine->Draw();
  downLine->Draw();
  leftLine->Draw();
  rightLine->Draw();
  
  Point p=Point(4,5,"*");
  Snake *snake = new Snake(p,4,RIGHT);
  snake->Draw();

  refresh();
  getch();
  endwin();

  return 0;
}