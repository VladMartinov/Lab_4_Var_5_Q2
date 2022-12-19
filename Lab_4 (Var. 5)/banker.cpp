#include "banker.h"
#include <iostream>

using namespace std;

Banker::Banker() {
	_cards = new Card[5];
	_countOfCard = 0;
}

Banker::~Banker() {
	delete[] _cards;
}

Banker::Banker(const Banker& copy) {
	_cards = copy._cards;
	_countOfCard = copy._countOfCard;
}

Banker& Banker::operator=(const Banker& _copyBanker) {
	_cards = _copyBanker._cards;
	_countOfCard = _copyBanker._countOfCard;
	return *this;
}

void Banker::setNewCards() {
	delete[] _cards;
	Card* newCards = new Card[5];

	_cards = newCards;
	_countOfCard = 0;

}

Card Banker::issueACard(Deck &deck) {
	wprintf(L"\n  (The Banker give for player the card)\n");
	return deck.getCard();
}

void Banker::takeACard(Deck &deck) {
	if (_countOfCard < 5) {
		_cards[_countOfCard] = deck.getCard();
		wprintf(L"\n (Banker) The card was taken: ");
		friendPrintCard(_cards[_countOfCard]);
		_countOfCard++;
	}
	else {
		wprintf(L"\n You have full pack of cards!");
	}
}

void Banker::printAllCard() {
	wprintf(L"\n%8Banker:");
	for (int i = 0; i < _countOfCard; i++) {
		friendPrintCard(_cards[i]);
	}
	if (sumOfCard() < 17) {
		wprintf(L"  ??");
	}
}

int Banker::sumOfCard() {
	int sum = 0;

	for (int i = 0; i < _countOfCard; i++) {
		
		if (stoi( _cards[i].getScoreCard() ) != 10)
		{
			if (stoi( _cards[i].getScoreCard() ) == 11 ) {
				if (sum < 11)
					sum += 11;
				else
					sum += 1;
			}
			else
				sum += stoi(_cards[i].getScoreCard());
		}
		else sum += 10;
	}

	return sum;
}