#include <iostream>
using namespace std;

void BinarySearch(int n, int t, int arr[]){
      int left = 0, right = n - 1;

    while(true) {

        int mid = (left + right) / 2;

        if(left>right){
            cout<<"No";
            break;
        }

        if(t > arr[mid]) {
            left = mid + 1;
        }

        else if(t < arr[mid]) {
            right = mid - 1;
        }
        else {
            cout << "Yes";
            break;
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int t;
    cin>>t;

    BinarySearch(n,t, arr);

}