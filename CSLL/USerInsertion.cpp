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
    }
} *head = NULL, *temp;
void printList()
{
    temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void insertEnd(int val)
{
    if (head == NULL)
    {
        head = new node(val);
        head->next = head;
        return;
    }
    temp = head;
    node *n = new node(val);
    n->next = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = n;
}
signed main()
{
    int n, k;
    // cin >> n;
    n = 5;
    while (n--)
    {
        cout << "Enter data to be inserted : ";
        cin >> k;
        insertEnd(k);
        // printList();
    }
    printList();
    return 0;
}