#include "player.h"
#include <iostream>

using namespace std;

Player::Player() {
	_money = 100;
	_cards = new Card[5];
	_countOfCard = 0;
}

Player::~Player() {
	delete[] _cards;
}

Player::Player(double money) {
	if (money > 0) _money = money;
	else _money = 0;
	_cards = new Card[5];
	_countOfCard = 0;
}

Player::Player(const Player& copy) {
	_money = copy._money;
	_cards = copy._cards;
	_countOfCard = copy._countOfCard;
}

Player& Player::operator=(const Player& _copyPlayer) {
	_money = _copyPlayer._money;
	_cards = _copyPlayer._cards;
	_countOfCard = _copyPlayer._countOfCard;
	return *this;
}

void Player::getTheCard(Card card) {
	if (_countOfCard < 5) {
		_cards[_countOfCard] = card;
		wprintf(L"\n (Player) The card was taken: ");
		friendPrintCard(_cards[_countOfCard]);
		_countOfCard++;
	}
	else {
		wprintf(L"\n You have full pack of cards!");
	}
}

void Player::setMoney(double money) { _money = money; }
double Player::getMoney () { return _money; }

void Player::setNewCards() {
	delete[] _cards;
	Card *newCards = new Card[5];

	_cards = newCards;
	_countOfCard = 0;

}

double Player::placeABet( double bet ) {
	if (bet > _money) {
		wprintf(L"\nInsufficient funds");
		return 0;
	}
	
	_money -= bet;
	return bet;
}

void Player::printAllCard(bool isStand = false) {
	wprintf(L"\n%8Player:");
	for (int i = 0; i < _countOfCard; i++) {
		friendPrintCard(_cards[i]);
	}
	if (!isStand) {
		wprintf(L"  ??");
	}
}

int Player::sumOfCard(bool isOne = false) {
	int sum = 0;

	for (int i = 0; i < _countOfCard; i++) {
		if (stoi(_cards[i].getScoreCard()) != 10) {
			if (stoi(_cards[i].getScoreCard()) == 11) {
				if(isOne){
					sum += 1;
				}
				else {
					wprintf(L"\n A it 1 or 11? (select 1/11)...\n");
					int selectedA = 0;
					cin >> selectedA;
					if (selectedA == 11)
						sum += 11;
					else
						sum += 1;
				}
			}
			else
				sum += stoi(_cards[i].getScoreCard());
		}
		else sum += 10;
	}

	return sum;
}