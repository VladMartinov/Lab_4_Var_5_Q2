/* 
* ===== author: Vlad Martinov (ICT - 3) =====
* 
* ������������ ������ �4 �� ���������������� �� �++, ������� �6
* ����� �����������,
* Double
* ��� ���� �� ����� � ��������� ������ ��� �� �����, ��� �� ���� ��� ��� � ������������� ��� �� �� ����� � �������
* 
*/

#include <iostream>
#include "gameDesk.h"

using namespace std;

int main() {

	// ��������� ������ ��� ������ ������
	GameDesk gameDesk = *(new GameDesk());

	// ����� ������ ������ ����
	gameDesk.startTheGame();


	return 0;
}
