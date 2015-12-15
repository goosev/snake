#include <iostream>
#include <ncurses.h>
#include <list>
#include "snake.h"

int main(int argc, char *argv[])
{

  int c;
  int maxheight;
  int maxwidth;
  initscr();
  curs_set(0);
  noecho();
  keypad(stdscr, true);
  halfdelay(1); //Устанавливаем ограничение по времени ожидания getch() в 0.1 сек
//  nodelay(stdscr, true);//Отключаем ограничение по времени ожидания getch()
  getmaxyx(stdscr,maxheight, maxwidth);

  Walls *walls = new Walls(maxwidth,maxheight);
  walls->Draw();
  
  char snake_sym[] = "*";
  Point p=Point(4,5,snake_sym);
  Snake *snake = new Snake(p,4,RIGHT);
  snake->Draw();

  char food_sym[] = "$";  
  FoodCreator *foodCreator = new FoodCreator(80,25,food_sym);
  Point food=foodCreator->CreateFood();
  food.Draw();
  
  while((c=getch())!=27)
  {
    if(walls->IsHit(*snake)||snake->IsHitTail())
      break;
    if(snake->Eat(food))
    {
      food=foodCreator->CreateFood();
      food.Draw();
    }
    else
    {
      snake->HandleKey(c);
      snake->Move();
      refresh();
    }
  }
  endwin();

  return 0;
}