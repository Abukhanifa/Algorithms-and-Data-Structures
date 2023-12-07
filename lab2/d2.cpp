#include <iostream>
#include <algorithm>
#include <vector>

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
    void sort(){
        node * first = head;
        node * second = nullptr;
        if (head == nullptr){
            return;
        }
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if (first -> val < second -> val){
                    swap(first->val, second->val);
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }
    void mode(){
        int numOfCurrent=1;
        node * current = head;
        int curr=current->val;
        int maxNum=1;
        current = current->next;
        while(current != NULL){
            if(current->val==curr){
                numOfCurrent++;
            }else{
                if(numOfCurrent>maxNum){
                    maxNum=numOfCurrent;
                }
                numOfCurrent=1;
                curr=current->val;
            }
            current = current->next;
        }
        if(numOfCurrent>maxNum){
            maxNum=numOfCurrent;
        }
        current = head;
        curr=current->val;
        numOfCurrent=1;
        current = current->next;
        while(current != NULL){
            if(current->val==curr){
                numOfCurrent++;
            }else{
                if(numOfCurrent==maxNum){
                    cout << curr << " ";
                }
                numOfCurrent=1;
                curr=current->val;
            }
            current = current->next;
        }
        if(numOfCurrent==maxNum){
            cout << curr << " ";
        }
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
    l.sort();
    l.mode();
    return 0;
}