#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define ull unsigned long long
using namespace std;

int main(){
    int n;
    cin>>n;
    ull m = 1e9 +7;
    vector<pair<string, string>> c;
    map<string, string> mp;

    for(int i=0; i<n*2; i++){
        string s;
        cin>>s;
        ull hs=0;
        ull p_pow = 1;

        for(int i=0; i<s.size(); i++){
            ull curr = (s[i] - '0' + 1) * p_pow % m;
            hs = (hs + curr) % m;
            p_pow = p_pow * 11 % m;
        }
        string ans;
        ans = to_string(hs);
        mp[s] = ans;
        c.push_back(make_pair(s, ans));
    }

    int cnt = 0;
    for(int i = 0; i<c.size(); i++){
        if(cnt == n){
            break;
        }
        if(mp.find(c[i].second) != mp.end()){
            cnt++;
            cout<< "Hash of string " << '"'<< c[i].first <<'"'<< " is " << c[i].second << endl;
        }
    }

}