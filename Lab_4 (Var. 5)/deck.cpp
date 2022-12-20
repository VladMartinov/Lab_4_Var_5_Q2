#include "deck.h"
#include "windows.h"
#include <time.h>
#include <iostream>

using namespace std;

// Конструкторы и деструктор
Deck::Deck() {
	Sleep(1000);
	countOfCard = 0;
	fillDeck();
	shuffleDeck();
}

Deck::~Deck() {
	for (int i = 0; i < 4; i++)
		delete[] cards[i];
	delete[] cards;
}

// Оставшееся кол-во кард в колоде
int Deck::getCountOfCard() const { return countOfCard; }

void Deck::fillDeck() {
	// массивы для заполнения калоды
	wstring* allScore = new wstring[] { L"\u0032", L"\u0033", L"\u0034", L"\u0035", L"\u0036", L"\u0037", L"\u0038", L"\u0039", L"\u0030", L"\u004A", L"\u0051", L"\u004B", L"\u0041" };
	wchar_t* allSuit = new wchar_t[] { L'\u2665', L'\u2663', L'\u2666', L'\u2660' };
	cards = new Card*[4];
	for (int i = 0; i < 4; i++) {
		cards[i] = new Card[13];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (j == 8) { // Т.к. 10 занимает состоит из 2х чаров
				cards[i][j] = *(new Card(L"\u0031\u0030", allSuit[i]));
			}
			else {
				cards[i][j] = *(new Card(allScore[j], allSuit[i]));
			}
			countOfCard++;
		}
	}

	delete[] allSuit;
	delete[] allScore;

}

void Deck::shuffleDeck() {
	
	srand(time(NULL));

	Card _secondCard(cards[0][0]);
	
	for(int i = 0; i < 4; i++) {
		for( int j = 0; j < 13; j++) {

			int firstICard = rand() % 4;
			int firstJCard = rand() % 13;

			int secondICard = rand() % 4;
			int secondJCard = rand() % 13;

			_secondCard = cards[firstICard][firstJCard];
			cards[firstICard][firstJCard] = cards[secondICard][secondJCard];
			cards[secondICard][secondJCard] = _secondCard;
			
		} 

	}

}

// Достаем карту снизу колоды
Card Deck::getCard() { 
	int i;
	if ((countOfCard / 4) >= 3) i = 3;
	else if ((countOfCard / 4) >= 2) i = 2;
	else if ((countOfCard / 4) >= 1) i = 1;
	else i = 0;
	int j = (countOfCard - 1) - i*13;
	countOfCard--;
	return cards[i][j];
}

// Обновляем колоду (не использовалось)
void Deck::newDeck() {
	Sleep(1000);
	countOfCard = 0;
	fillDeck();
	shuffleDeck();
}
