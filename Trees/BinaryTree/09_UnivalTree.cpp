#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *createTree(node *root)
{
    int data;
    cout << "Enter data for node : ";
    cin >> data;
    root = new node(data);

    // if data == -1, return NULL; // for convinence
    if (data == -1)
        return NULL;

    cout << "Enter data for left of " << data << " " << endl;
    root->left = createTree(root->left);

    cout << "Enter data for right of " << data << " " << endl;
    root->right = createTree(root->right);
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
bool isUnivalTree(node *root)
{
    if (root == NULL)
        return true;
    if (root->left)
    {
        if (root->left->data != root->data)
            return false;
    }
    if (root->right)
    {
        if (root->right->data != root->data)
            return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
signed main()
{
    node *root = NULL;
    root = createTree(root);

    // data :
    //           1
    //     3               5
    //          7        6         8
    //

    // data1 : 1 3 -1 7 -1 -1 5 6 -1 -1 8 -1 -1

    // data2 : 1 1 1 -1 -1 -1 -1

    cout << endl;
    levelOrderTraversal(root);

    if (isUnivalTree(root))
    {
        cout << "Unival Tree" << endl;
    }
    else
    {
        cout << "Not a Unival Tree" << endl;
    }
    return 0;
}