#pragma once
#include "deck.h"

class Banker {
public:
	Banker();
	Banker(const Banker& copy);

	~Banker();

	Banker& operator= (const Banker& _copyBanker);

	void setNewCards();

	Card issueACard(Deck &deck);
	void takeACard(Deck &deck);
	
	void printAllCard();
	int sumOfCard();

private:
	Card* _cards;
	int _countOfCard;

};