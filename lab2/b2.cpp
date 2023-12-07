#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
    string val;
    node * next;
    node(string x){
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
    void add(string x){
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
    void shift(int shift){
        for(int i=0; i<shift; i++){
            this->add(head->val);
            head=head->next;
        }
    }
        
    
    
};

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    ll l;
    for(int i = 0; i < n; ++i){
        cin >> s;
        l.add(s);
    }
    l.shift(k);
    l.print();
    return 0;
}