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
} *head = NULL;
void printList()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertFront(int val)
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
}
void insertEnd(int val)
{
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertPos(int val, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }
    int i = 1;
    node *temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    node *nn = new node(val);
    nn->next = temp->next;
    temp->next = nn;
}
signed main()
{
    // int n;
    // cin >> n;
    int k;
    while (true)
    {
        int opn;
        cout << "Insert front? : ";
        cin >> opn;
        if (opn == 1)
        {
            cout << "Enter element to be inserted at the front: ";
            cin >> k;
            insertFront(k);
        }
        else if (opn == 2)
        {
            cout << "Enter element to be inserted at the end: ";
            cin >> k;
            insertEnd(k);
        }
        else if (opn == 3)
        {
            int pos;
            cout << "Enter element and to be inserted : ";
            cin >> k >> pos;
            insertPos(k, pos);
        }
        else
            break;
    }
    printList();
    return 0;
}