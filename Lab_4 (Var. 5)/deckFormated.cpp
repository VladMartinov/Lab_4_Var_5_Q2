#include "DeckFormated.h"

// Адаптер для класса Deck, который принимает в себя объект этого класса и решафлит его 3 раза (якобы такие правило нашего казино, если не решафлить то не принимаем)

wstring DeckFormated::format(const Deck& deck) {
	return to_wstring(deck.getCountOfCard());
}