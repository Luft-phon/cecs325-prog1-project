#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
private:
	char rank;  // '2-9' 'A, J, Q, K'
	char suit;  // 'H, D, S, C'
public:
	Card();
	Card(char r, char s);

	void display() const;
	int compare(const Card& other) const;
	char getRank() const { return rank; }
	char getSuit() const { return suit; }
};


#endif
