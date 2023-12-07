#include <iostream>
using namespace std;
 
void merge(int arr[], int left, int mid, int right){
    int leftSize = mid - left + 1, rightSize = right - mid;
    int l = 0, r = 0, index = left;
    int leftArr[leftSize], rightArr[rightSize];
 
    for(int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
 
    for(int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];
 
    while(l < leftSize and r < rightSize)
        if(leftArr[l] <= rightArr[r])
            arr[index++] = leftArr[l++];
        else
            arr[index++] = rightArr[r++];
 
    while(l < leftSize)
        arr[index++] = leftArr[l++];
    while(r < rightSize)
        arr[index++] = rightArr[r++];
}
 
void MergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 
int main(){
    int n = 12;
    int arr[n] = {5, 9, 1, 7, 2, 3, 11, 10, 12, 4, 8, 6};
 
    MergeSort(arr, 0, n - 1);
 
    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
}