#include <bits/stdc++.h>
using namespace std;
#define int long long int
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
} *head = NULL, *temp;
void insertEnd(int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void printList()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Iterative

void reverseIterative()
{
    node *cur = head;
    node *prev = NULL;
    while (cur)
    {
        node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}



// Recursive

// node *reverseList(node *head)          
// {
//     if (head == NULL || head->next == NULL)
//         return head;
//     node *newHead = reverseList(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newHead;
// }
signed main()
{
    int n, k;
    cin >> n; // no of elements
    while (n--)
    {
        cin >> k;
        insertEnd(k);
    }
    reverseIterative();
    printList();
    return 0;
}