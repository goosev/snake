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

  char border_sym[] = "+";
  HorizontalLine *upLine = new HorizontalLine(0,78,0,border_sym);
  HorizontalLine *downLine = new HorizontalLine(0,78,24,border_sym);
  VerticalLine *leftLine = new VerticalLine(0,24,0,border_sym);
  VerticalLine *rightLine = new VerticalLine(0,24,78,border_sym);
  upLine->Draw();
  downLine->Draw();
  leftLine->Draw();
  rightLine->Draw();

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