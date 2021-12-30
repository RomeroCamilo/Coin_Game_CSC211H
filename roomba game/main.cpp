//CAMILO ROMERO
//ID: 23885919
//FALL 2021, CSC211H
//SUBMISSION: 11/11/21
//TIME: 10:00 PM
//INSTRUCTOR NAME: DR.AZHAR

#include <iostream>
#include <stdlib.h>
#include <fstream>

//only need to include robot class since all other classes are already included in this class

#include "robot.h"

//writing to the file.
void openWriteFile(string fileScript);

using namespace std;

void greeting();


int main() {

  
  string name;

  robot Player1;
  robot Player2;
  world myWorld;

  //user choice;
  char choice;

  //points of the robot.
  int x,y;
  //Player 1 and 2 (robot) score
  int playerOne = 0;
  int playerTwo = 0;

  //pointing to score.
  int* ptr1 = nullptr;
  int* ptr2 = nullptr;
  ptr1=&playerOne;
  ptr2=&playerTwo;

  int coinsFound = 0;
  int firstCoin = 0;
  int secondCoin = 1;
  int thirdCoin = 2;

  //movements needed to win
  int movementCount = 0;

  greeting();

  cout<<"What is your name?";
  cin>>name;
  openWriteFile("ROBOT vs ");
  openWriteFile(name);
  openWriteFile(" WINNER: ");

  //setting the values of three coins (0-9)
  for(int i =0; i<3;i++)
  {
    //setting the values for the three coins.
    x = rand()%10;
    y = rand()%10;
    //storing the values by index.
    myWorld.set(i,x,y);
  }


  cout<<"The coins have been set! Starting Player and Robot at (0,0)..."<<endl<<endl;


  //starting robot up at (0,0) and facing north.
  Player2.init();
  Player2.turnAntiCW();
  //starting user/player at (0,0) and facing north.
  Player1.init();
  Player1.turnAntiCW();

  //DISPLAYING THE CONTROL MENU
  Player1.userMenu();
  cout<<endl;
  
  do
  {
    //display location
    Player1.currentLocation(1);
    Player2.currentLocation(2);
    cout<<endl;
    //player decides the movement.
    cout<<"Movement choice: ";
    cin>>choice;
    Player1.userChoice(choice);
    
    //robot movements will move through all possible elements. 
    if(playerTwo == 3)
    {
      break;
    }
    if((Player2.getxVal() == myWorld.getX(firstCoin) && Player2.getyVal() == myWorld.getY(firstCoin)) || (Player2.getxVal() == myWorld.getX(secondCoin) && Player2.getyVal() == myWorld.getY(secondCoin)) || (Player2.getxVal() == myWorld.getX(thirdCoin) && Player2.getyVal() == myWorld.getY(thirdCoin) ))
    {
      cout<<endl;
      Player2.print();
      *ptr2+=1;
      cout<<"Im Robot! and I've found " << *ptr2 <<" coin('s)"<<endl<<endl;
    }
    Player2.robotMovement();
    
    cout<<endl;
  }while(!(playerOne == 3 || *ptr2 == 3));


if(playerOne > *ptr2)
{
  cout<<"PLAYER 1 WINS!!!"<<endl<<endl;
  openWriteFile(name);
  openWriteFile("\n");
}
else
{
  cout<<"The Robot has won. You lose..."<<endl<<endl;
  openWriteFile("ROBOT\n");
}

  string name1,vs,name2,check,result;

  cout<<"\tALL PREVIOUS PLAYERS RESULTS"<<endl;

  //Will open the file, and print the result of each previous player. Each name will have their result.
  ifstream infile;
  infile.open( "theScore.txt", ios::in );
  if(infile.is_open())
  {
    while(infile >> name1 >> vs >> name2 >> check>>result)
    {
      cout<<name1<<" "<<vs<<" "<<name2<<" "<< check <<" "<<result<<endl;
    }
      infile.close();
  }
  





return 0;
}

void greeting()
{
  cout<<"\nWelcome, can you find the coins before the Robot does? Three coins will be set randomly in a 10x10 Map. Whoever finds all three coins, wins!"<<endl<<endl;;
}

void openWriteFile(string fileScript) {
  ofstream scoreFile;
  scoreFile.open("theScore.txt",ios::out | ios::app);
  scoreFile << fileScript;
  scoreFile.close();
}




