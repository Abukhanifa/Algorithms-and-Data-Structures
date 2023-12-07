#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    Node * current = head;
    if(p>0){
        for(int i=1; i<p; i++){
            current = current->next;
        }
        node->next=current->next;
        current->next=node;
    }else{
        node->next=head;
        head=node;
    }
    return head;
}
 
Node* remove(Node* head, int p){
    Node * current = head;
    if(p>0){
        for(int i=1; i<p; i++){
            current = current->next;
        }
        current->next=current->next->next;
    }else{
        head=head->next;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node * current = head;
    Node * prevcurrent = nullptr;
    
    if(p1==p2){
        return head;
    }

    for(int i=0; i<p1; i++){
        prevcurrent=current;
        current = current->next;
    }
    if(p2>0){
        if(p1==0){
            head=head->next;
        }else prevcurrent->next=current->next;
        Node * newpos = head;
        for(int i=1; i<p2; i++){
            newpos = newpos->next;
        }
        current->next=newpos->next;
        newpos->next=current;
    }else{
        prevcurrent->next=current->next;
        current->next=head;
        head=current;
    }
    return head;
}
 
Node* reverse(Node* head){
    Node * prev = nullptr;
    Node * current = head;
    while(head!=nullptr){
        head=head->next;
        current->next=prev;
        prev=current;
        current=head;
    }
    return prev;
}
 
void print(Node* head){
    Node * current = head;
    if(current==nullptr){
        cout <<"-1";
    }
    while(current != nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    Node * current = head;
    Node * last = head;
    while(last->next!=nullptr){
        last=last->next;
    }
    if(head->next==nullptr){
        return head;
    }
    for(int i=0; i<x; i++){
        current=head->next;
        last->next=head;
        last=last->next;
        last->next=nullptr;
        head=current;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    Node * current = head;
    Node * last = head;
    int size=1;
    while(last->next!=nullptr){
        last=last->next;
        size++;
    }
    if(head->next==nullptr){
        return head;
    }
    for(int i=0; i<size-x; i++){
        current=head->next;
        last->next=head;
        last=last->next;
        last->next=nullptr;
        head=current;
    }
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}