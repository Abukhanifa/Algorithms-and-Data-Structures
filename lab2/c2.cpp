#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteEverySecond() {
        Node* current = head;
        while (current && current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;

    LinkedList list;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        list.add(val);
    }

    list.deleteEverySecond();

    list.display();

    return 0;
}