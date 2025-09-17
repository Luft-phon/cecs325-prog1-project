#include "Deck.h"
#include <utility> 
using namespace std;
Deck::Deck() : topIndex(0){
	const char suits[] = { 'C', 'S', 'D', 'H' };
	const char ranks[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

	int index = 0;
	for (int s = 0; s < 4; ++s ) {
		for (int r = 0; r < 13; ++r) {
			cards[index] = Card(ranks[r], suits[s]);
		}
	}
}

Card Deck::deal() {
	if (topIndex < 52) {
		return cards[topIndex++];
	} else {
		// Handle the case where there are no more cards to deal
		throw std::out_of_range("No more cards in the deck");
	}
}

void Deck::display() const {
	for (int r = 0; r < 4; ++r) {
		for (int i = 0; i < 13; ++i) {
			int index = r * 13 + i;
			cards[index].display();
			if (i < 12) cout << ",";
		}
		cout << "\n";
	}
}

void Deck::shuffle() {
	for (int i = 51; i > 0; --i) {
		int j = rand() % (i + 1);
		std::swap(cards[i], cards[j]);
	}
	topIndex = 0; // Reset topIndex after shuffling
}
