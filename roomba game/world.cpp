#include "world.h"

#include <iostream>

using namespace std;

//prints all three coin locations after setting them.
void world :: print() const
{
  int count = 1;
  cout<<endl;
  for(int i =0;i<3;i++)
  {
    cout<<"Coin " << count << " location: ";
    coin[i].print();
    cout<<endl;
    count++;
  }
}

//sets location of a coin by index value.
void world :: set(int i, int x, int y)
{
  coin[i].set(x,y);
}

 int world :: getX(int i)
 {
   return coin[i].getX();
 }

 int world :: getY(int i)
 {
   return coin[i].getY();
 }







