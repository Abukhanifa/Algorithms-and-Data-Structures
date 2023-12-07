#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

#define ll long long
using namespace std;

int main(){
    string s;
    cin>>s;
    ll p = 31;
    ll m = 9948424647760667;
    ll arr[s.size()];

    for(int i=0; i<s.size(); i++){
        arr[i] = s[i] - 'a' + 1;
    }

    unordered_set <ll> st;
    for(int i=0; i<s.size(); i++){
        ll curr = arr[i];
        st.insert(curr);
        for(int j = i+1; j<s.size(); j++){
            curr = (curr * p + arr[j]) % m;
            st.insert(curr);
        }
    }

    cout<<st.size();
    
    
}