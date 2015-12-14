#include <ncurses.h>
#include <iostream>
#include <list>
#ifndef SNAKE_H
#define SNAKE_H

enum Direction
{
LEFT,
RIGHT,
UP,
DOWN
};

class Point
{
public:
  int x,y;
  char* sym;

  Point(int _x, int _y, char* _sym);
  Point();
//  Point(Point &p);
  
  void Draw();
  void Clear();
  void Move(int offset, Direction direction);
};

class Figure
{
public:
  Figure();
  std::list<Point> pList;
  void Draw();
};

class HorizontalLine : public Figure
{
public:
  HorizontalLine(int xLeft, int xRight, int y, char* sym);

};

class VerticalLine : public Figure
{
public:
  VerticalLine(int yUp, int yDown, int x, char* sym);
};

class Snake : public Figure
{
public:
  Snake(Point tail, int lenght, Direction _direction);
  void Move();
  Point GetNextPoint();
  Direction direction;
};

#endif