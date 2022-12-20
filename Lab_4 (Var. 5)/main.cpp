/* 
* ===== author: Vlad Martinov (ICT - 3) =====
* 
* Лабораторная работа №4 по программированию на С++, Вариант №6
* стиль европейский,
* Double
* Два туза не нашел в интернете ответа что за стиль, сам не знаю что это и преподаватель так же не знает я узнавал
* 
*/

#include <iostream>
#include "gameDesk.h"

using namespace std;

int main() {

	// Выделение памяти под объект класса
	GameDesk gameDesk = *(new GameDesk());

	// Вызов метода начала игры
	gameDesk.startTheGame();


	return 0;
}
