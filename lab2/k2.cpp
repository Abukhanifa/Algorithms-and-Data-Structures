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
       size=0;
    }
    void add(string x){
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
    
    string removeDuplicateNode(){   
        node * curr = head;
        bool isrepeated ;
            if(curr->next == NULL ){
                return(curr->val);
            }
            while(curr != NULL ){
                node *index= head;
                isrepeated = false;
                while(index!=NULL){
                    if(curr!=index && curr->val == index->val){
                        isrepeated=true;
                        break;
                    }
                    index=index->next;
                }
                if(!isrepeated){
                    return(curr->val);
                }
                curr=curr->next;
            }
            return("-1");
    }
};

int main(){
    int n, m;
    cin >> n;
    dll l[n];

    string s;
    for(int i = 0; i < n; ++i){
        cin >> m;
        for(int j =0 ; j< m; ++j){ 
            cin >> s;
            l[i].add(s);
            // l[i].print();
            // cout << endl;
            cout  << l[i].removeDuplicateNode()<< " ";
        }
        cout << endl;
    }

    return 0;
}
