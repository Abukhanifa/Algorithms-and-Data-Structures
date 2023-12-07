#include <iostream>
#include <string>

using namespace std;

bool Equal(string s1, string s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    while (i >= 0 || j >= 0) {
        int bscount1 = 0;
        int bscount2 = 0;

        // Count consecutive backspace characters and move the index accordingly
        while (i >= 0 && (s1[i] == '#' || bscount1 > 0)) {
            if (s1[i] == '#') {
                bscount1++;
            } else {
                bscount1--;
            }
            i--;
        }

        while (j >= 0 && (s2[j] == '#' || bscount2 > 0)) {
            if (s2[j] == '#') {
                bscount2++;
            } else {
                bscount2--;
            }
            j--;
        }

        // If characters at current positions don't match, the strings are not equal
        if (i >= 0 && j >= 0 && s1[i] != s2[j]) {
            return false;
        }

        // If one string has more characters left, the strings are not equal
        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    // Both strings are equal
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (Equal(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}