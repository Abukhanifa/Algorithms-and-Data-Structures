#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int T;
    int N;
    cin >> N;
    int y;
    int p[N];

    for(int i=0; i<N; i++){
        cin >> p[i];
        
    }
    for(int i=0; i<N; i++){
        y=-1;
        for(int j=i-1; j>=0; j--){
            if(p[i]>=p[j]){
                y=p[j];
                break;
            }
        }
        cout << y << " ";
    } 

}