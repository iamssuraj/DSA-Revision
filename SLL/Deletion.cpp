#include <bits/stdc++.h>
using namespace std;
class node
{
    int data;
    friend void display(node *);

public:
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void display(node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
signed main()
{
    // Insert 23 in a linked list of 1,3,5,7 between 3 and 5
    node *head = new node(1);   // 1
    node *second = new node(3); // 3
    node *third = new node(5);  // 5
    node *fourth = new node(7); // 7

    head->next = second;
    second->next = third;
    third->next = fourth;

    node *inserted = new node(23);
    second->next = inserted;
    inserted->next = third; // Insert 23
    display(head);

    //deleting 23

    //1 --> 3 --> 23 --> 5 --> 7 --> NULL
    second->next = fourth;
    third->next = NULL;
    display(head);

    return 0;
}