#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;

    // Add all stone weights to the max-heap
    for (int stone : stones) {
        maxHeap.push(stone);
    }

    // Continue smashing stones until there is at most 1 stone left
    while (maxHeap.size() >= 2) {
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();

        // Calculate the new weight after smashing
        int newWeight = abs(x - y);

        // Add the new weight back to the max-heap
        if (newWeight > 0) {
            maxHeap.push(newWeight);
        }
    }

    // Check if there's a stone left
    if (!maxHeap.empty()) {
        return maxHeap.top();
    } else {
        return 0; // No stones left
    }
}

int main() {
    int N; // Number of stones
    cin >> N;
    vector<int> stones(N);

    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    int result = lastStoneWeight(stones);
    cout << result << endl;

    return 0;
}