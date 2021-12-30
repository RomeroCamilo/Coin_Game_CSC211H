#include "robot.h"
#include <iostream>
using namespace std;


//setting the initial location of the robot and direction
void robot :: init()
{
  x = 0;
  y = 0;
  location.set(x,y);
  orientation = east;
  if(orientation == east)
   {
     orientationn = "east";
   }
   else if(orientation == west)
   {
     orientationn =  "west";
   }
   else if(orientation == south)
   {
     orientationn = "south";
   }
   else
   {
     orientationn = "north";
   }
}

 void robot :: setOrientation(enum orientation_type )
 {  
   if(orientation == east)
   {
     orientationn = "east";
   }
   else if(orientation == west)
   {
     orientationn =  "west";
   }
   else if(orientation == south)
   {
     orientationn = "south";
   }
   else
   {
     orientationn = "north";
   }
  }


void robot :: print()const
{
  cout<<"I am at " ; location.print(); 
  cout<<" and I am facing " << orientationn <<"."<<endl;
}

//Setter for the orientation member function.
//void robot :: setOrientation(string orientation)
//{
 // this->orientation = orientation;
//}

//controls
bool robot :: forward()
{
  //will return either true or false depending if robot moved forward or not.
  bool check;
   if(orientationn == "east" && eastEnd() == false && x!= 9)
   {
     x++;
     location.set(x,y);
     check = true;
   }
   else if(orientationn == "west" && westEnd() == false && x!=0)
   {
     x--;
     location.set(x,y);
     check = true;
   }
   else if(orientationn == "north" && northEnd() == false && y!=9)
   {
     y++;
     location.set(x,y);
     check = true;
   }
   else if(orientationn == "south" && southEnd() == false && y!= 0)
   {
     y--;
     location.set(x,y);
     check = true;
   }
   else
   {
     check = false;
   }
   return check;
}

void robot :: turnCW()
{
  if(orientationn == "east")
  {
    orientationn = "south";
  }
  else if(orientationn == "south")
  {
    orientationn = "west";
  }
  else if(orientationn == "west")
  {
    orientationn = "north";
  }
  else if(orientationn == "north")
  {
    orientationn = "east";
  }
}

void robot :: turnAntiCW()
{
  if(orientationn == "east")
  {
    orientationn = "north";
  }
  else if(orientationn == "north")
  {
    orientationn = "west";
  }
  else if(orientationn == "west")
  {
    orientationn = "south";
  }
  else if(orientationn == "south")
  {
    orientationn = "east";
  }
}

//checks if robot has reached edge of the world.
bool robot :: eastEnd()
{
  if(location.getX()==9)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool robot :: westEnd()
{
  if(location.getX()==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool robot :: northEnd()
{
  if(location.getY()==9)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool robot :: southEnd()
{
  if(location.getY()==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool robot :: zag()
{
  if(orientationn == "east" && eastEnd()==true)
  {
    turnCW();
    forward();
    turnCW();
  }
  return true;
}

bool robot :: zig()
{
  if(orientationn == "west" && westEnd()==true)
  {
    turnAntiCW();
    forward();
    turnAntiCW();
  }
  return true;
}

//return x and y from location
  int robot :: getxVal()
  {
    return location.getX();
  }
  
  int robot :: getyVal()
  {
    return location.getY();
  }

  //menu
  void robot:: userMenu()
  {
    cout<<"\tROBOT CONTROLS"<<endl;
    cout<<"Type in F to move forward: "<<endl;
    cout<<"Type in C to turn clockwise: "<<endl;
    cout<<"Type in A to turn anticlockwise: "<<endl;
  }
  
  void robot:: userChoice(char Y)
  {

    do
    {
      if(!(Y == 'F' || Y == 'C' || Y == 'A'))
      {
          cout<<"You did not enter a valid choice. Try again! "<<endl;
          cout<<"Choice: ";
          cin>>Y;
      }

      if(Y == 'F')
      {
        forward();
      }
      else if(Y == 'C')
      {
        turnCW();
      }
      else if(Y == 'A')
      {
        turnAntiCW();
      }
     
    }while(!(Y == 'F' || Y == 'C' || Y == 'A'));
  }

  void robot :: currentLocation( int one)
  {
    cout<<"Player "<< one <<" current Location: (" << x << "," << y <<")"<<endl;
    cout<<"Facing " << orientationn <<endl;
  }

  string robot :: getOrientation()
  {
    return orientationn;
  }
  

//robots movement automated.
  void robot :: robotMovement()
  {
    if(getOrientation() == "north")
    {
      if(northEnd()==false)
      {
        forward();
      }
      else
      {
        turnCW();
        forward();
        turnCW();
      }

    }
    else if(getOrientation() == "south")
    {
      if(southEnd()==false)
      {
        forward();
      }
      else
      {
        turnAntiCW();
        forward();
        //now go back to facing north.
        turnAntiCW();
      }
    }
  }



