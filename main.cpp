#include <iostream>
#include <ncurses.h>
#include <list>
#include "snake.h"

int main(int argc, char *argv[])
{

  int c;

  initscr();
  curs_set(0);
  noecho();
  keypad(stdscr, true);
  halfdelay(1); //Устанавливаем ограничение по времени ожидания getch() в 0.1 сек

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
  while((c=getch())!=27)
  {
    switch(c)
    {
     case ERR:
        break;
      case KEY_LEFT:
        snake->direction=LEFT;
      break;
      case KEY_RIGHT:
        snake->direction=RIGHT;
      break;
      case KEY_UP:
        snake->direction=UP;
      break;
      case KEY_DOWN:
        snake->direction=DOWN;
      break;
    }
    snake->Move();
    refresh();
  }
  refresh();
  getch();
  endwin();

  return 0;
}