#pragma once
#include <string>

using namespace std;

class Card
{
	friend void friendPrintCard(Card&);
public:
	Card();
	Card(wstring scoreCard, wchar_t suitCard);
	Card(const Card& copy);
	~Card();

	wstring getScoreCard();
	wchar_t getSuitCard();

	Card& operator= (const Card &_copyCard);

	void setScoreCard(wstring score);
	void setSuitCard(wchar_t suit);

private:
	wstring _scoreCard;
	wchar_t _suitCard;
};
