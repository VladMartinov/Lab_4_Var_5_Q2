#include <iostream>
#include "gameDesk.h"

using namespace std;

int main() {
	GameDesk gameDesk = *(new GameDesk());

	gameDesk.startTheGame();


	return 0;
}