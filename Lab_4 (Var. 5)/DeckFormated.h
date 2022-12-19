#pragma once
#include "deck.h"
#include "IFormattable.h"

class DeckFormated : Deck, IFormattable {
public:
	wstring format(const Deck& deck) override;
};