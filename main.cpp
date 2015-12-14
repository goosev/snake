#include <iostream>
#include <ncurses.h>

class Point
{
public:
  int x,y;
  char* sym;

  void Point::Draw()
  {
    move(y,x);
    printw(sym);
  }

};
        

int main(int argc, char *argv[])
{

  Point p1;
  p1.x=1;
  p1.y=3;
  p1.sym="*";

  Point p2;
  p2.x=4;
  p2.y=5;
  p2.sym="#";
  
  
  initscr();
  curs_set(0);
  p1.Draw();
  p2.Draw();
  refresh();
  getch();
  endwin();
  return 0;
}