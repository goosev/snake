#include <iostream>
#include <ncurses.h>

static void Draw(int x, int y, char* sym)
{
  mvprintw(y,x,sym);
}

int main(int argc, char *argv[])
{
  int x1=1;
  int y1=3;
  char* sym1="*";

  int x2=4;
  int y2=5;
  char* sym2="#";
  
  
  initscr();
  curs_set(0);
  Draw(x1,y1, sym1);
  Draw(x2,y2, sym2);
  refresh();
  getch();
  endwin();
  return 0;
}