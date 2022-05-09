#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
signed main()
{
    node *head = new (node);
    node *second = new (node);
    node *third = new (node);

    head->data = 5;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 25;
    third->next = NULL;

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}