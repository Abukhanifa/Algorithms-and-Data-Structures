#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    string val;
    Node(string _val)
    {
        prev = NULL;
        next = NULL;
        val = _val;
    }
};

Node *head = NULL;
Node *tail = NULL;
int cnt;
void add_back(string s)
{
    Node *n = new Node(s);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
}
void add_front(string s)
{
    Node *n = new Node(s);
    if (tail == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;
    }
}
bool empty()
{
    return(head==NULL);
}
void erase_front()
{
    if (head->next != NULL)
    {
        head->next->prev=NULL;
        head=head->next;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}
void erase_back()
{
    if (tail->prev != NULL)
    {
        tail->prev->next=NULL;
        tail=tail->prev;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}
string front()
{
    return head->val;
}
string back()
{
    return tail->val;
}
void clear()
{
    head = NULL;
    tail = NULL;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "add_front")
        {
            string t;
            cin >> t;
            add_front(t);
            cout << "ok" << endl;
        }
        if (s == "add_back")
        {
            string t;
            cin >> t;
            add_back(t);
            cout << "ok" << endl;
        }
        if (s == "erase_front")
        {
            if (empty())
            {
                cout << "error" << endl;
            }
            else
            {
                cout << front() << endl;
                erase_front();
            }
        }
        if (s == "erase_back")
        {
            if (empty())
            {
                cout << "error" << endl;
            }
            else
            {
                cout << back() << endl;
                erase_back();
            }
        }
        if (s == "front")
        {
            if (empty())
            {
                cout << "error" << endl;
            }
            else
            {
                cout << front() << endl;
            }
        }
        if (s == "back")
        {
            if (empty())
            {
                cout << "error" << endl;
            }
            else
            {
                cout << back() << endl;
            }
        }
        if (s == "clear")
        {
            clear();
            cout << "ok" << endl;
        }
        if (s == "exit")
        {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}