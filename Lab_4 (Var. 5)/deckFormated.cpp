#include "DeckFormated.h"

// ������� ��� ������ Deck, ������� ��������� � ���� ������ ����� ������ � �������� ��� 3 ���� (����� ����� ������� ������ ������, ���� �� ��������� �� �� ���������)

wstring DeckFormated::format(const Deck& deck) {
	return to_wstring(deck.getCountOfCard());
}