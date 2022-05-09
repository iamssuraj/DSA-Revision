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
    cout << "Before Insertion" << endl;
    display(head);

    // After Insertion
    node *inserted = new node(23);
    second->next = inserted;
    inserted->next = third;
    cout << "After Insertion of 23" << endl;
    display(head);

    node *attach = new node(10);
    attach->next = head;
    head = attach;
    cout << "After Insertion of 10" << endl;
    display(head);
    return 0;
}