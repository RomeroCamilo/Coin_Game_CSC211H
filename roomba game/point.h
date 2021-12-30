#include <iostream>

using namespace std;

//the main purpose of this class is so the other classes can use this Point class to access x and y and set the values for the coin.

class Point{
  private:
  int x;
  int y;
  
  public:
  
  //prints values of x and y.
  void print()const;

  //sets the values of x and y.
  void set(int x,int y);

  int getX();

  int getY();

};