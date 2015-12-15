#include <ncurses.h>
#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
  bool IsHit(Point p);
};

class Figure
{
public:
  Figure();
  std::list<Point> pList;
  void Draw();
//protected:
  bool IsHit(Figure figure);
private:
  bool IsHit(Point point);
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
  void HandleKey(int c);
  bool Eat(Point food);
  bool IsHitTail();
protected:
  Direction direction;

  
};

class FoodCreator
{
public:
  int mapWidth;
  int mapHeight;
  char* sym;
  FoodCreator(int _mapWidth, int _mapHeight, char* _sym);
  Point CreateFood();
  int iSecret;
 
};

class Walls
{
public:
  Walls(int mapWidth, int mapHeight);
  std::list<Figure> wallList;
  void Draw();
  bool IsHit(Figure figure);
};
#endif