#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
    int val;
    node * next;
    node(int val){
        this->val=val;
        this->next=NULL;
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
        node * curr = head;
        while(curr != NULL){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
    void insert(int data, int pos){
        node * n = new node(data);
        node * curr = head;
        if(pos>0){
            for(int i=1; i<pos; i++){
                curr = curr->next;
            }
            n->next=curr->next;
            curr->next=n;
        }else{
            n->next=head;
            head=n;
        }
    }
};

int main(){
    ll A;
    int n;
    int num;
    int data;
    int position;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        A.add(num);
    }
    cin >> data;
    cin >> position;
    A.insert(data,position);
    A.print();

    return 0;
}