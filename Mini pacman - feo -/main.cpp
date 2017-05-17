#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

#include "myconio.h"
#include "Pmemori.h"
#include "CharacterController.h"

using namespace std;

int main(int argc, char const *argv[]) {

  CharacterController *player = new CharacterController(PmemoriB,playerCoord);

  player->gameLoop();


  cin.get();
  return 0;
}
