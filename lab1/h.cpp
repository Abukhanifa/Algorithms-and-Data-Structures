#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n){
    if(n<=1){
        return false;
    }
    if(n==2){
        return true;
    }
    if(n%2==0){
        return false;
    }
    
    for(int i=3; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    if(isprime(n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}