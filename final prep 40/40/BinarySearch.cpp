#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>v, int target){
    int left = 0, right = v.size()-1;
    while(left<=right){
        int mid = (left + right) / 2 ;
        if(target<v[mid]){
            right = mid - 1;
        }
        else if(target > v[mid]){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }

    return -1;
}