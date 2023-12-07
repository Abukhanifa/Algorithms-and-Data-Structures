#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
    int val;
    node * next;
    node(int x){
        val = x;
        next = NULL;
    }
    void print(){
        cout << val << endl;
    }
};

struct ll{
    node * head;
    node * tail;
    ll(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        node * n = new node(x);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
    }
    void print(){
        node * current = head;
        while(current != NULL){
            cout << current->val << " ";
            current = current->next;
        }
    }
    void check(int x){
        node * current = head;
        int i=0;
        int diff=abs(current->val-x);
        current = current->next;
        int index;
        while(current!=NULL){
            i++;
            if(abs(current->val-x)<diff){
                diff=abs(current->val-x);
                index=i;
            }
            current = current->next;
        }
        cout << index;
    }
};

int main(){
    int n;
    cin >> n;
    int a;
    ll l;
    for(int i = 0; i < n; ++i){
        cin >> a;
        l.add(a);
    }
    int k;
    cin >> k;
    l.check(k);
    return 0;
}

