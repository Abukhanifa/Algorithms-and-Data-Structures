#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int isPrime(long int number) {
    if (number == 0 || number == 1 || (number % 2 == 0 && number > 2)) {
        return 0; 
    } else {
        for (long int i = 3; i <= (long int)sqrt(number) + 1; i++) {
            if (number % i == 0) {
                return 0; 
            }
        }
        return 1; 
    }
}

int main(){
    int b;
    cin >> b;
    vector<int> c;
    for(int i=2;i<100000;i++){
        if(isPrime(i)){
            c.push_back(i);
        }
    }
    cout << c[c[b-1]-1];
}