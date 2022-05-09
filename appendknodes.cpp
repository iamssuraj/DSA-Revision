/* example :
before :
1 -> 2 -> 3 -> 4 -> 5 -> NULL
k = 2
after:
4 -> 5 -> 1 -> 2 -> 3 -> NULL
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    friend void display(Node *);
    friend void append(Node *, int);
    friend int count(Node *);

public:
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *head;
void display(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int count(Node *head)
{
    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void append(Node *temp, int pos)
{
    int val = count(temp) - pos;
    int i = 1;
    while (i < val - 1)
    {
        i++;
        temp = temp->next;
    }
    Node *temp2 = temp;
    Node *temp3 = temp->next;
    temp2->next = NULL;
    temp = temp3;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
    head = temp3;
}
signed main()
{
    head = new Node(5);
    Node *second = new Node(6);
    Node *third = new Node(7);
    Node *fourth = new Node(3);
    Node *fifth = new Node(2);
    Node *sixth = new Node(4);
    Node *seventh = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    cout << "Before : " << endl;
    display(head);
    cout << "After : " << endl;
    append(head, 4);
    display(head);
    return 0;
}
