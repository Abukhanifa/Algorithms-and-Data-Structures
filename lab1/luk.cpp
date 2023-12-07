#include <iostream>
#include <vector>

using namespace std;

bool canRepeatTrick(int N) {
    vector<int> deck(N);

    // Initialize the deck with cards numbered from 1 to N
    for (int i = 0; i < N; i++) {
        deck[i] = i + 1;
    }

    vector<int> originalDeck = deck; // Store the original deck for comparison

    for (int i = 1; i <= N; i++) {
        // Perform the steps of the trick
        vector<int> pickedCards;
        pickedCards.push_back(deck.front()); // Pick up 1 card and put it on the back
        deck.erase(deck.begin());

        // Check if the picked card is equal to 'i'
        if (pickedCards.back() != i) {
            return false; // Trick cannot be repeated
        }

        // Put 'i' cards on the back of the deck one by one
        for (int j = 0; j < i; j++) {
            if (!deck.empty()) {
                pickedCards.push_back(deck.front());
                deck.erase(deck.begin());
            } else {
                return false; // Trick cannot be repeated
            }
        }

        // Put the picked cards outside of the deck
        for (int card : pickedCards) {
            deck.push_back(card);
        }
    }

    // Check if the deck is the same as the original deck
    return deck == originalDeck;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (canRepeatTrick(N)) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}