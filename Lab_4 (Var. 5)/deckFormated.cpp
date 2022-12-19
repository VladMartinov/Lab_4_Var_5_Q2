#include "DeckFormated.h"

wstring DeckFormated::format(const Deck& deck) {
	try {
		for (int i = 0; i < 3; i++)
			this->shuffleDeck();
	}
	catch (exception e) {
		return L"False";
	}

	return L"True";
}