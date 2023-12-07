#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct node{
    int val;
    node * next;

    node()
    {
        val = 0;
        next = NULL;
    }
};

int findMaxSum(int n, node *head)
{
    node * cur = head;
    int best_sum = 0;
    int current_sum = 0;
    while (cur != NULL)
    {
        current_sum = max(0, current_sum + cur->val);
        best_sum = max(best_sum, current_sum);
        cur = cur->next;
    }
    if(best_sum == 0)
    {
        node * curn = head;
        int big_ng = -10000;
        while (curn != NULL)
        {
            if(curn->val > big_ng)
            {
                big_ng = curn->val;
            }
            curn = curn->next;
        }
        return big_ng;
        
    }
    else
    {
        return best_sum;
    }
    
}

int main()
{
    int n;
    cin >> n;

    node *head, *tail;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        node *cur = new node();
        cur->val = x;

        if (i == 1)
        {
            head = tail = cur;
        }
        else{
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}
