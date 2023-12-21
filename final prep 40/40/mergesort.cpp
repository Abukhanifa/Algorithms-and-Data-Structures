#include <iostream>
using namespace std;
 
void merge(int arr[], int left, int mid, int right){
    int leftsize = mid-left+1, rightsize = right - mid;
    int l=0, r=0, index = left;
    int leftarr[leftsize], rightarr[rightsize];

    for(int i=0; i<leftsize; i++){
        leftarr[i] = arr[left+i];
    }
    for(int i=0; i<rightsize; i++){
        rightarr[i] = arr[mid+i+1];
    }

    while(l<leftsize && r<rightsize){
        if(leftarr[l] <= rightarr[r]){
            arr[index++] = leftarr[l++];
        }
        else{
            arr[index++] = rightarr[r++];
        }
    }

    while(l<leftsize){
        arr[index++] = leftarr[l++];
    }
    while(r<rightsize){
        arr[index++] = rightarr[r++];
    }
}
 
void MergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 
