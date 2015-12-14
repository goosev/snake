#include <iostream>
#include <ncurses.h>

class Point
{
public:
  int x,y;
  char* sym;

  Point(int _x, int _y, char* _sym)
  {
    x=_x;
    y=_y;
    sym=_sym;
  };
  
  void Draw()
  {
    move(y,x);
    printw(sym);
  };

};
        

int main(int argc, char *argv[])
{

  Point *p1=new Point(1,3,"*");
/*
  Point *p2=new Point();
  p2->x=4;
  p2->y=5;
  p2->sym="#";
*/
  
  initscr();
  curs_set(0);
  p1->Draw();
  //p2->Draw();
  refresh();
  getch();
  endwin();
  return 0;
}