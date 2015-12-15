#include "snake.h"

Point::Point(int _x, int _y, char* _sym)
{
  x=_x;
  y=_y;
  sym=_sym;
}

Point::Point()
{
  x=0;
  y=0;
  sym=NULL;
}

/*
Point::Point(Point &p)
{
  x=p.x;
  y=p.y;
  sym=p.sum;
}
*/

void Point::Move(int offset, Direction direction)
{
  switch(direction){ 
    case RIGHT:
    x=x+offset;
    break;
    case LEFT:
    x=x-offset;
    break;
    case UP:
    y=y-offset;
    break;
    case DOWN:
    y=y+offset;
    break;
  }
}

void Point::Draw()
{
  move(y,x);
  printw(sym);
}

void Point::Clear()
{
  char clear_sym[]=" ";
  sym=clear_sym;
  Draw();
}

bool Point::IsHit(Point p)
{
  return x==p.x && y==p.y;
}

HorizontalLine::HorizontalLine(int xLeft, int xRight, int y, char* sym):Figure()
{
  for(int x = xLeft; x<=xRight; x++)
  {
    Point p=Point(x, y, sym);
    pList.push_back (p);
  }
}

VerticalLine::VerticalLine(int yUp, int yDown, int x, char* sym):Figure()
{
  for(int y = yUp; y<=yDown; y++)
  {
    Point p=Point(x, y, sym);
    pList.push_back (p);
  }

}

Figure::Figure()
{
  ;
}

void Figure::Draw()
{
  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
    it->Draw();
}

bool Figure::IsHit(Figure figure)
{
  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
    if(figure.IsHit(*it))
      return true;
  return false;
}

bool Figure::IsHit(Point point)
{
  for (std::list<Point>::iterator it = pList.begin(); it != pList.end(); it++)
    if(it->IsHit(point))
      return true;
  return false;
}

Snake::Snake(Point tail, int lenght, Direction _direction):Figure()
{
  direction=_direction;
  for(int i = 0; i<lenght; i++)
  {
    Point p=tail;
    p.Move(i, direction);
    pList.push_back (p);
  }
}

void Snake::Move()
{
  Point tail = pList.front();
  pList.pop_front();
  Point head=GetNextPoint();
  pList.push_back(head);
  
  head.Draw();
  tail.Clear();
  
}

Point Snake::GetNextPoint()
{
  Point head=pList.back();
  Point nextPoint = head;
  nextPoint.Move(1, direction);
  return nextPoint;
}

bool Snake::Eat(Point food)
{
  Point head=GetNextPoint();
  if(head.IsHit(food))
  {
    food.sym=head.sym;
    pList.push_back(food);
    return true;
  }
  else
    return false;
}

void  Snake::HandleKey(int c)
{
  switch(c)
  {
    case ERR:
    break;
    case KEY_LEFT:
      direction=LEFT;
    break;
    case KEY_RIGHT:
      direction=RIGHT;
    break;
    case KEY_UP:
      direction=UP;
    break;
    case KEY_DOWN:
      direction=DOWN;
    break;
  }
}

bool Snake::IsHitTail()
{
  Point head=pList.back();
/*  for (int i=0; i<pList.size(); i++)
    if(head.IsHit(pList[i]))
      return true;*/
  for (std::list<Point>::iterator it = pList.begin(); it != --pList.end(); it++)
    if(head.IsHit(*it))
      return true;

  return false;
}

FoodCreator::FoodCreator(int _mapWidth, int _mapHeight, char* _sym)
{
  mapWidth=_mapWidth;
  mapHeight=_mapHeight;
  sym=_sym;

  srand (time(NULL));
}

Point FoodCreator::CreateFood()
{
  int x = rand()%(mapWidth-2) + 1;;
  int y = rand()%(mapHeight-2) + 1;;
  return Point(x,y,sym);
}

Walls::Walls(int mapWidth, int mapHeight)
{
  char border_sym[] = "+";
  HorizontalLine upLine = HorizontalLine(0, mapWidth-2, 0, "+");
  HorizontalLine downLine = HorizontalLine(0, mapWidth-2, mapHeight-1, "+");
  VerticalLine leftLine = VerticalLine(0, mapHeight-1, 0, "+");
  VerticalLine rightLine = VerticalLine(0, mapHeight-1, mapWidth-2, "+");
  wallList.push_back(upLine);
  wallList.push_back(downLine);
  wallList.push_back(leftLine);
  wallList.push_back(rightLine);

}

bool Walls::IsHit(Figure figure)
{
  for (std::list<Figure>::iterator it = wallList.begin(); it != wallList.end(); it++)
    if(it->IsHit(figure))
      return true;
  return false;
}
void Walls::Draw()
{
  for (std::list<Figure>::iterator it = wallList.begin(); it != wallList.end(); it++)
    it->Draw();
}

