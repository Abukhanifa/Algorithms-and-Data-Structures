#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Heap{
    vector<int> heap;

    int parent(int i){
        return(i - 1) / 2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    void insert(int value){
        this->heap.push_back(value);
        int i = this->heap.size()-1;
        while(i!=0 && this->heap[parent(i)] < this->heap[i]){
            swap(this->heap[i], this->heap[parent(i)]);
            i = parent(i);
        }

    }

    void heapify(int i){
        int l = this->left(i);
        int r = this->right(i);
        int biggest = i;
        if(l < this->heap.size() && this->heap[l] > this->heap[biggest])
            l = biggest;
        if(r < this->heap.size() && this->heap[r] < this->heap[biggest])
            r = biggest;
        
        if(biggest != i){
            swap(this->heap[i], this->heap[biggest]);
            this->heapify(biggest);
        }

}

};