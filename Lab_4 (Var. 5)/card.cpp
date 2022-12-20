#include <iostream>
#include <iomanip>
#include "card.h"
#include "io.h"
#include "fcntl.h"


//  онструкторы и деструкторы
Card::Card() {
	_scoreCard = L'\u0032';
	_suitCard = L'\u2665';
}

Card::Card(wstring scoreCard, wchar_t suitCard) {
	_scoreCard = scoreCard;
	_suitCard = suitCard;
}

Card::Card(const Card & _copy) {
	_scoreCard = _copy._scoreCard;
	_suitCard = _copy._suitCard;
}

Card& Card::operator=(const Card& copyCard) {
	_scoreCard = copyCard._scoreCard;
	_suitCard = copyCard._suitCard;
	return *this; 
}

Card::~Card() {
	_scoreCard.clear();
}

// ¬озвращает кол-во очков (если J,Q,K то 10 и т.п.)
wstring Card::getScoreCard()	{
	if (_scoreCard.find(L'\u004A') != string::npos || _scoreCard.find(L'\u0051') != string::npos || _scoreCard.find(L'\u004B') != string::npos)
		return L"\u0031\u0030";
	else if (_scoreCard.find(L'\u0041') != string::npos )
		return L"\u0031\u0031";
	return _scoreCard; 
}
// ¬озврат масти карты
wchar_t Card::getSuitCard()	{ return _suitCard; }

void Card::setScoreCard(wstring _score) { _scoreCard = _score; }
void Card::setSuitCard(wchar_t _suit) { _suitCard = _suit; }

// friend оператор дл€ вывода 
ostream& operator<<(ostream& os, const Card& value) {
	wcout << setw(4) << value._scoreCard << value._suitCard;
	return os;
}

// ѕросто метод дл€ вывода (использовал раньше до перегрузки потока вывода)
void friendPrintCard(Card &a) {
	wprintf(L"  %s%c", a._scoreCard.c_str(), a._suitCard);
}