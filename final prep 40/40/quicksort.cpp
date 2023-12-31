#include <iostream>
using namespace std;
 
void QuickSort(int arr[], int left, int right) {
    if(left < right) {
        int l = left, r = right;
        int mid = (left + right) / 2;
 
        while(l <= r) {
            while(arr[l] < arr[mid]) l++;
            while(arr[r] > arr[mid]) r--;
            if(l <= r) swap(arr[l++], arr[r--]);
        }
 
        QuickSort(arr, left, r);
        QuickSort(arr, l, right);
    }
}
 