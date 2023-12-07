#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
    string val;
    node * next;
    node * prev;
    node(string x){
        val = x;
        next = NULL;
        prev = NULL;
    }
    void print(){
        cout << val << endl;
    }
};

struct dll{
    node * head;
    node * tail;
    int size;
    dll(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void add(string x){
        size++;
        node * n = new node(x);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            n->prev=tail;
            tail->next = n;
            tail = n;
        }
    }
    void print(){
        node * curr = head;
        while(curr != NULL){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
    void printback(){
        node * curr = tail;
        while(curr != NULL){
            cout << curr->val << endl;
            curr = curr->prev;
        }
    }

    void removeDuplicateNode(){
        node * curr = tail;
        node * index = curr->prev;
            while(index != NULL){
                if(index->val == index->next->val){
                    index->next->prev = index->prev;
                    if(index->prev != NULL){
                        index->prev->next = index->next;
                    }
                    size--;
                }
                index = index->prev;
            }
    }
};

int main(){
    int n;
    cin >> n;
    string a;
    dll l;
    for(int i = 0; i < n; ++i){
        cin >> a;
        l.add(a);
    }
    l.removeDuplicateNode();
    cout << "All in all: " << l.size << endl;
    cout << "Students:" << endl;
    l.printback();

    return 0;
}