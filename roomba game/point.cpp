  #include "point.h"
  #include <iostream>

  
  
  void Point:: print()const
  {
    cout<<"("<<x<<","<<y<<")"<<endl;
  }

  void Point:: set(int x,int y)
  {
    this->x = x;
    this->y = y;
  }

  int Point::getX()
  {
    return x;
  }

  int Point::getY()
  {
    return y;
  }

  //incrementing and decrementing value of x and y functions

  
  