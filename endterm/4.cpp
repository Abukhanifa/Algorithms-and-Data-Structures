#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//глобальные перемены 
string s,t;

/* hash value calculating for Rabin karp */
int main(){
    int p = 31;
    vector<long long> p_pow(max(s.length(), t.length()));
    p_pow[0] = 1;

// считаем все степени p 
    for(int i=0; i< p_pow.size(); ++i){
        p_pow[i] = p_pow[i-1] * p;

    }
// считаем хэш от строки S
    vector <long, long> h(t.length());
    for(int i=0; i<t.size(); ++i){
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if(i) h[i] += h[i-1];
    }

// перебираем все подстроки T длины |S| и сравниваем их
    long long hs = 0;
    for(int i=0; i<s.length(); ++i){
        hs += (s[i] - 'a' + 1) * p_pow[i];
    }

    for(int i=0; i+s.length()-1<t.length(); ++i){
        long long curr = h[i+s.length()-1];
        if(i) curr -= h[i-1];
        // приводим хэши к одной степени и сравниваем
        if(curr == hs * p_pow[i]){
            cout<< i << " ";
        }
    }


}