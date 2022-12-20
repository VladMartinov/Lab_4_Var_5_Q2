#pragma once
#include "card.h"

class Deck {
public:
	// == Конструкторы и деструкторы ==
	Deck();

	~Deck();

	// Геттер
	int getCountOfCard() const;
	
	// == Методы ==
	void fillDeck();
	void shuffleDeck();
	void newDeck();
	
	Card getCard();

private:
	Card** cards;
	int countOfCard;
};