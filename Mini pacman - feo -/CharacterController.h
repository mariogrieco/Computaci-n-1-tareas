#ifndef CharacterController_H
#define CharacterController_H

#include "Pmemori.h"
#include "conio.h"
#include "windows.h"

using namespace std;

class CharacterController : public Pmemori {

private:
  bool gameloop;
  char key;
  int counter;

public:

  CharacterController() : Pmemori(){
    gameloop = 1;
    counter = 0;
  }

  CharacterController(int a[20][20],int p[2]) : Pmemori(a,p){
    gameloop = 1;
    counter = 0;
  }

  int gameLoop(){
    red1:
    while ( gameloop ) {

        searchPlayer();
        mprint();
        key = getch();
        counter++;
        if ( counter > 5 ) {
            counter = 0;
            goto red1;
        }
        else if ( key == 'q' ) {
          gameloop = 0;
        }
        else if ( key == 'd' ) {
          moveRigth(0,+1);
        }
        else if ( key == 'a'){
          moveLeft(0,-1);
        }
        else if ( key == 'w' ) {
          moveTop(-1,0);
        }
        else if ( key == 's' ) {
          moveDown(+1,0);
        }
        else {
          cout << "unknow option!" << endl;
        }
    }
  }

  int searchPlayer(){



    if ( enemigoOneMove(-1,0) == 0 ) {

    }

  }

  int moveLeft(int x,int y){
      playerMove(x,y);
  }

  int moveRigth(int x,int y){
    playerMove(x,y);
  }

  int moveTop(int x,int y){
    playerMove(x,y);
  }

  int moveDown(int x,int y){
    playerMove(x,y);
  }

};

#endif
