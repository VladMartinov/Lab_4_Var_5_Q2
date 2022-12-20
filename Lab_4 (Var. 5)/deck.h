#pragma once
#include "card.h"

class Deck {
public:

	Deck();

	~Deck();

	int getCountOfCard() const;
	
	void fillDeck();
	void shuffleDeck();
	void newDeck();
	
	Card getCard();

private:
	Card** cards;
	int countOfCard;
};