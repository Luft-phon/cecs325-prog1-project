#include <iostream>
#include <string>
#include "Deck.h"
using namespace std;

int main() {
    Deck deck;

    string p1, p2;
    cout << "Enter the name of the first player: ";
    getline(cin, p1);
    if (p1.empty()) getline(cin, p1); 
    cout << "Enter the name of the second player: ";
    getline(cin, p2);

    cout << "\n Original Deck\n\n";
    deck.display();

    deck.shuffle();

    cout << "\n Shuffled Deck\n\n";
    deck.display();

    int p1Wins = 0, p2Wins = 0, ties = 0;

    for (int game = 1; game <= 26; ++game) {
        cout << "\nGame " << game << "\n";
        cout << "--------\n";

        Card c1 = deck.deal();
        Card c2 = deck.deal();

        cout << "\t" << p1 << "=>";
        c1.display();
        cout << "\n";

        cout << "\t" << p2 << "=>";
        c2.display();
        cout << "\n\n";

        int res = c1.compare(c2);
        if (res > 0) {
            cout << p1 << "=> Winner\n";
            ++p1Wins;
        }
        else if (res < 0) {
            cout << p2 << "=> Winner\n";
            ++p2Wins;
        }
        else {
            cout << "Tie game\n";
            ++ties;
        }
    }

    cout << "\n------Final Stats-------\n\n";
    cout << "       " << p1 << " vs. " << p2 << "\n\n";

    cout << "Wins   " << p1Wins << "          " << p2Wins << "\n";
    cout << "Losses " << (26 - p1Wins - ties) << "          " << (26 - p2Wins - ties) << "\n";
    cout << "Ties   " << ties << "           " << ties << "\n";

    return 0;
}
