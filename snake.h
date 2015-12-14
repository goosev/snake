#include <ncurses.h>
#include <iostream>
#ifndef SNAKE_H
#define SNAKE_H
class Point
{
public:
  int x,y;
  char* sym;

  Point(int _x, int _y, char* _sym);
  Point();
  
  void Draw();
};
#endif