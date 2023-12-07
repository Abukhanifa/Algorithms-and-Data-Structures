#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> f;
    vector<int> s;
    for(int i=0; i<5; i++){
        int card;
        cin >> card;
        f.push_back(card);
    }
    for(int i=0; i<5; i++){
        int card;
        cin >> card;
        s.push_back(card);
    }
    int move=0;
    while(!f.empty() && !s.empty()){
        
        if(f[0]==9 && s[0]==0){
            s.push_back(f[0]);
            s.push_back(s[0]);
            f.erase(f.begin());
            s.erase(s.begin());
        }else if(f[0]==0 && s[0]==9){
            f.push_back(f[0]);
            f.push_back(s[0]);
            f.erase(f.begin());
            s.erase(s.begin());
        }else if(f[0]>s[0]){
            f.push_back(f[0]);
            f.push_back(s[0]);
            f.erase(f.begin());
            s.erase(s.begin());
        }else{
            s.push_back(f[0]);
            s.push_back(s[0]);
            f.erase(f.begin());
            s.erase(s.begin());
        }
        move++;
        if(move>1000000){
            cout << "botva";
            return 0;
        }
    }
    if(f.empty()){
        cout << "Nursik " << move << endl;
    }else{
        cout << "Boris " << move << endl;
    }
}