#ifndef Pmemori_H
#define Pmemori_H

#include <iostream>
#include "myconio.h"

  int PmemoriB[20][20] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1},
  {1,0,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
  {1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,0,1},
  {1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
  {1,0,0,0,0,0,1,1,1,-1,1,1,1,0,0,0,0,0,0,1},
  {1,1,1,1,1,0,1,-1,-1,-1,-1,-1,1,0,1,1,1,1,1,1},
  {0,0,0,0,0,0,1,-1,-1,3,-1,-1,1,0,0,0,0,0,0,0},
  {1,1,1,1,1,0,1,-1,-1,-1,-1,-1,1,0,1,1,1,1,1,1},
  {1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
  {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
  {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
  {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };

  int refresh[20][20] = {
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  {-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
  };

  int playerCoord[2] = { 1,1};

using namespace std;

class Pmemori {
protected:
  int Tablero[20][20];
  int PC[2];
  int enemiOneMove[2];
public:
      Pmemori(){

      }

      Pmemori(int a[20][20],int p[2]){
        for (int i = 0; i < 20; i++) {
          for (int x = 0; x < 20; x++) {
             Tablero[i][x] = a[i][x];
          }
        }
        PC[0] = p[0];
        PC[1] = p[1];
        enemiOneMove[0] = 9;
        enemiOneMove[1] = 9;
      }

      void mprint(){
        textbgcolor(WHITE,BLACK);
        for (int i = 0; i < 20; i++) {
          for (int x = 0; x < 20; x++) {
              if ( Tablero[i][x] == 1 && ( Tablero[i][x] != refresh[i][x] ) ) {
                textbgcolor(BLUE,BLACK);
                gotoxy(x,i);
                cout << "|";
              }
              else if ( Tablero[i][x] == 0 && ( Tablero[i][x] != refresh[i][x] ) ) {
                textbgcolor(GRAY,BLACK);
                gotoxy(x,i);
                cout <<((char)250);
              }
              else if ( Tablero[i][x] == 2 && ( Tablero[i][x] != refresh[i][x] ) ) {
                textbgcolor(LIGHT_YELLOW,BLACK);
                gotoxy(x,i);
                cout <<((char)184);
              }
              else if ( Tablero[i][x] == 3 && ( Tablero[i][x] != refresh[i][x] ) ){
                textbgcolor(LIGHT_RED,BLACK);
                gotoxy(x,i);
                cout <<((char)169);
              }
              else if ( Tablero[i][x] == -1 && ( Tablero[i][x] != refresh[i][x] ) ) {
                textbgcolor(BLACK,BLACK);
                gotoxy(x,i);
                cout <<((char)250);
              }
              refresh[i][x] = Tablero[i][x];
          }
          textbgcolor(WHITE,BLACK);
        }
      }

      int playerMove(int x,int y){

       if ( (PC[0]+x < 20 && PC[1]+y < 20) || (PC[0]+x >= 0 && PC[1]+y >= 0)) {
         if ( PC[0] == 9 && PC[1] == 0) {
           if ( ( x == 0 ) && ( y == -1 ) ) {
               Tablero[PC[0]][PC[1]] = -1;
               PC[0] = 9;
               PC[1] = 19;
               Tablero[PC[0]][PC[1]] = 2;
               return 1;
           }
         }
        if ( PC[1] == 19 && PC[0] == 9 ) {
           if ( x == 0 && y ==  1 ) {
             Tablero[PC[0]][PC[1]] = -1;
             PC[0] = 9;
             PC[1] = 0;
             Tablero[PC[0]][PC[1]] = 2;
             return 1;
           }
         }
         if ( (Tablero[PC[0]+x][PC[1]+y] == 0) || (Tablero[PC[0]+x][PC[1]+y] == -1) ) {
                if ( Tablero[PC[0]][PC[1]] != -1 ) {
                    Tablero[PC[0]][PC[1]] = -1;
                }
                Tablero[PC[0]+x][PC[1]+y] = 2;
                PC[0] += x;
                PC[1] += y;
                return 0;
            }
          }
          return 0;
      }

      int enemigoOneMove(int x,int y){

       if ( (enemiOneMove[0]+x < 20 && enemiOneMove[1]+y < 20) || (enemiOneMove[0]+x >= 0 && enemiOneMove[1]+y >= 0)) {
         if ( enemiOneMove[0] == 9 && enemiOneMove[1] == 0) {
           if ( ( x == 0 ) && ( y == -1 ) ) {
               Tablero[enemiOneMove[0]][enemiOneMove[1]] = 0;
               enemiOneMove[0] = 9;
               enemiOneMove[1] = 19;
               Tablero[enemiOneMove[0]][enemiOneMove[1]] = 3;
               return 1;
           }
         }
        if ( enemiOneMove[1] == 19 && enemiOneMove[0] == 9 ) {
           if ( x == 0 && y ==  1 ) {
             Tablero[enemiOneMove[0]][enemiOneMove[1]] = 0;
             enemiOneMove[0] = 9;
             enemiOneMove[1] = 0;
             Tablero[enemiOneMove[0]][enemiOneMove[1]] = 3;
             return 1;
           }
         }
         if ( (Tablero[enemiOneMove[0]+x][enemiOneMove[1]+y] == 0) || (Tablero[enemiOneMove[0]+x][enemiOneMove[1]+y] == -1) ) {
                if ( Tablero[enemiOneMove[0]][enemiOneMove[1]] != 1 ) {
                    Tablero[enemiOneMove[0]][enemiOneMove[1]] = 0;
                }
                Tablero[enemiOneMove[0]+x][enemiOneMove[1]+y] = 3;
                enemiOneMove[0] += x;
                enemiOneMove[1] += y;
                return 1;
            }
          }
          return 0;
      }
};

#endif
