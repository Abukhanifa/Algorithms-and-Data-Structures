#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int j=0;
    int query=0;
    while(n>1){
        if(s[j]=='S'){
            if(query>0){
                s.erase(s.begin()+j);
                n--;
                j--;
            }
            query--;
        }else if(s[j]=='K'){
            if(query<0){
                s.erase(s.begin()+j);
                n--;
                j--;
            }
            query++;
        }
        if(query>n || query<-n){
            if(s[j]=='K'){
                cout << "KATSURAGI";
            }else if(s[j]=='S'){
                cout << "SAKAYANAGI";
            }
            break;
        }
        // cout << s << endl;
        j=(++j)%n;
    }

    if(s=="K"){
        cout << "KATSURAGI";
    }else if(s=="S"){
        cout << "SAKAYANAGI";
    }
}