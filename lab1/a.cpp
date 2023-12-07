#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int s;
    cin >> s;
    int n;
    vector<int> nums;
    while(cin >> n){
        nums.push_back(n);
    }
    while(nums.size() <s){
        nums.push_back(nums.back());
    }
    for(auto x: nums){
        deque<int> deck;
        if(x==0){
            cout << -1 << endl;
        }else{
            for(int i=x; i>0;i--){
                deck.push_front(i);
                for(int j=0;j<i;j++){
                    deck.push_front(deck.back());
                    deck.pop_back();
                }
        }
            while(!deck.empty()){
                cout << deck.front() << " ";
                deck.pop_front();
            }
        
        cout << endl;
        }
        
    }
    return 0;
}
    
