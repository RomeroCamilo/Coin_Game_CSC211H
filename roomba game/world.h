#include <iostream>

#include "point.h"

using namespace std;

class world{
  private:
  //array to set the location of three coins.
  Point coin[3];


  public:
  //prints location of all three coins.
  void print() const;

  //sets the location of the i'th coin. Three coins in total.
  void set(int i, int x, int y);

  int getX(int i);
  int getY(int i);



};