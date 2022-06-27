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
void traverseLeft(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    cout << root->data << " ";
    if (root->left)
        traverseLeft(root->left);
    else
        traverseLeft(root->right);
}

void traverseLeaf(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    traverseLeaf(root->left);
    traverseLeaf(root->right);
}
void traverseRight(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right)
        traverseRight(root->right);
    else
        traverseRight(root->left);
    cout << root->data << " ";
}
void boundaryTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    traverseLeft(root->left);

    traverseLeaf(root->left);
    traverseLeaf(root->right);

    traverseRight(root->right);
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

    // data2 : 7 9 8 10 -1 -1 9 -1 -1 8 -1 -1 7 6 -1 -1 -1

    // data3 : 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1

    // data4 : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << endl;
    boundaryTraversal(root);
    return 0;
}