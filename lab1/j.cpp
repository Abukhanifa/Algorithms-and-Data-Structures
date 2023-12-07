#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque <int> dq;
    string input;

    while (cin >> input) {
        if (input == "!") {
            if (dq.empty()) {
                cout << "error" << endl;
            } else {
                cout << dq.front() + dq.back() << endl;
            }
        } else if (input == "+") {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if (input == "-") {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if (input == "*") {
            if (dq.empty()) {
                cout << "error" << endl;
            } else {
                
                dq.pop_front();
                dq.pop_back();
            }
        }
    }

    return 0;
}