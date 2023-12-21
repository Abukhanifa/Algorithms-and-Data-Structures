#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node *prev;

    Node(){
        this->val = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int val, Node *prev, Node *next){
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

struct DoublyLinkedList{
    int size = 0;
    Node *head;
    Node *tail;

    DoublyLinkedList(){
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    } 

    void add_front(int val){
        Node *NewNode = new Node(val);
        if(this->size == 0){
            this->head = NewNode;
            this->tail = NewNode;
        }
        else{
            NewNode->next = this->head;
            this->head->prev = NewNode;
            this->head = NewNode;
        }
        this->size++;
    }

    void push_back(int val) {
        Node *newNode = new Node(val);
        if (this->size == 0) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }


};