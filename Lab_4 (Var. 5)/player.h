#pragma once
#include "IPlayerActions.h"
#include "card.h"

class Player : public IPlayerActions {
public:

	Player();
	Player(double money);
	Player(const Player& copy);

	~Player();

	//Card* removeCard();
	
	Player& operator= (const Player& _copyPlayer);
	
	void getTheCard(Card card);

	void setMoney(double money);
	double getMoney();

	void setNewCards();

	double placeABet( double bet ) override;

	void printAllCard(bool isStand);
	int sumOfCard(bool isOne);

private:
	double _money;
	Card* _cards;
	int _countOfCard;
};