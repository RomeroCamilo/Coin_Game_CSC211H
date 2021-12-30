#include <iostream>

#include "world.h"

using namespace std;

class robot{
  private:
  //Stores location of the robot.
  Point location;

  world get;
  
  enum orientation_type
  {
    east = 1 , west = 2, south = 3, north = 4
  };

  //variables to set the direction
  int orientation;
  string orientationn;
  
  int x;
  int y;


  public:
  //sets the default values of location of robot and orientation.
  void init();

  void print()const;

  void setOrientation(enum orientation_type );

  //Setter for the orientation member function.
  //void setOrientation(string orientation);

  //controls
  bool forward();
  void turnCW();
  void turnAntiCW();
  
  //checks if robot has reached end of the world.
  bool eastEnd();
  bool westEnd();
  bool northEnd();
  bool southEnd();

  //return x and y from location
  int getxVal();
  int getyVal();
  string getOrientation();

  
  bool zag();
  bool zig();

  //choice

  void userChoice(char Y);

  void userMenu();

  void currentLocation(int one);

  void robotMovement();

};