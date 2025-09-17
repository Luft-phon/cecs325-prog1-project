#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
private:
	Card cards[52];
	int topIndex;
public:
	Deck();
	Card deal();
	void display() const;
	void shuffle();
};

#endif