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

void PreOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
void PostOrder(node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
signed main()
{
    node *root = NULL;
    root = createTree(root);

    // data :
    //           1
    //     3               5
    // -1          7        6         8
    //-1  -1   -1   -1   -1  -1    -1  -1

    // data : 1 3 -1 7 -1 -1 5 6 -1 -1 8 -1 -1
    cout << endl;
    cout << endl;
    cout << endl;


    cout << "PreOrder Traversal : ";
    PreOrder(root);
    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "InOrder Traversal : ";
    InOrder(root);
    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "PostOrder Traversal : ";
    PostOrder(root);
    cout << endl;
    cout << endl;
    cout << endl;
    
    return 0;
}