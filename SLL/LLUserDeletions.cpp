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
void printList()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertEnd(int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *n = new node(val);
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void deleteFront()
{
    node *t = head;
    head = head->next;
    cout << t->data << " deleted." << endl;
    delete t;
}
void deleteEnd()
{
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *t = temp->next;
    cout << t->data << " deleted." << endl;
    temp->next = NULL;
    delete t;
}
void deletePos(int pos)
{
    if (pos == 1)
    {
        deleteFront();
        return;
    }
    if (pos <= 0)
    {
        cout << "Invalid Position." << endl;
        return;
    }
    temp = head;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    node *t = temp->next;
    temp->next = temp->next->next;
    delete t;
}
signed main()
{
    int k;
    while (true)
    {
        cout << "Insert at end : ";
        cin >> k;
        insertEnd(k);
        if (k < 0)
            break;
    }
    // deleteFront();
    // deleteFront();
    // deleteFront();
    // deleteFront();
    // deleteEnd();
    // deleteEnd();
    // deleteEnd();
    // deleteEnd();
    printList();
    // while (true)
    // {
    //     int pos;
    //     cout << "Delete at pos : ";
    //     cin >> pos;
    //     deletePos(pos);
    //     if (pos <= 0)
    //         break;
    // }
    deletePos(2);
    printList();
    return 0;
}