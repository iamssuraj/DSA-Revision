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
void reverse()
{
    node *currentNode = head, *prevNode = NULL, *nextNode = NULL;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}
signed main()
{
    int n, k;
    cin >> n; // no of elements
    while (n--)
    {
        cin >> k;
        insertEnd(k);
    }
    reverse();
    printList();
    return 0;
}