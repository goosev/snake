#include <ncurses.h>
#include <iostream>
#include <list>
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

class HorizontalLine
{
public:
  HorizontalLine(int xLeft, int xRight, int y, char* sym);
  std::list<Point> pList;

  void Draw();
};

class VerticalLine
{
public:
  VerticalLine(int yUp, int yDown, int x, char* sym);
  std::list<Point> pList;

  void Draw();
};

#endif