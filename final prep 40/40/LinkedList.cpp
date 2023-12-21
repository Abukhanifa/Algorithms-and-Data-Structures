#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;

    Node(){
        this->val = 0;
        this->next = nullptr;
    }

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }

    Node(int val, Node *next){
        this->val = val;
        this->next = next;
    }

};

struct LinkedList{
    int size;
    Node *head;
    Node *tail;

    LinkedList(){
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void add(int val){
        Node *NewNode = new Node(val);
        if(this->size == 0){
            this->head = NewNode;
            this->tail = NewNode;
        }
        else{
            NewNode->next = this->head;
            this->head = NewNode;
        }
        this->size++;
    }

    void print(){
        Node *curr = this->head;
        while(curr != nullptr){
            cout<<curr->val<< " ";
            curr = curr -> next;
        }
        cout << endl;
    }
};