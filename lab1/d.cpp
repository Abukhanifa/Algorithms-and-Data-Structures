#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string s1;
    cin >> s1;
    stack <char> st;
    for(auto x: s1){
        if(st.empty() || st.top()!=x){
            st.push(x);
        }else st.pop();
    }
    if(st.empty()){
        cout << "YES";
    }else cout<<"NO";
}

    