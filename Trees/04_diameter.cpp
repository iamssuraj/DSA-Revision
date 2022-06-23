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
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int height(node *root)
{

    // Base Condition
    if (root == NULL)
    {
        return 0; // no child so height is 0;
    }

    int leftt = height(root->left);   // depth of left subtree
    int rightt = height(root->right); // depth of right subtree
    return max(leftt, rightt) + 1;    // maximum depth of trees + root node height
}

// Solution with O(n^2) time complexity
int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int op1 = diameter(root->left);                     //  diameter of left subtree
    int op2 = diameter(root->right);                    //  diameter of right subtree
    int op3 = height(root->left) + height(root->right); // height of subtrees

    int ans = max(op1, max(op2, op3));
    return ans;
}

// Efficient Solution O(n) time complexity
pair<int, int> diameterFast(node *root)
{
    // pair<diameter, height>

    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int a = left.first;
    int b = right.first;
    int c = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(a, max(b, c));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

signed main()
{
    node *root = NULL;
    root = createTree(root);

    // data :
    //           1
    //      3               5
    // -1     7         6         8
    //    -1   -1    -1  -1    -1   -1

    // data : 1 3 -1 7 -1 -1 5 6 -1 -1 8 -1 -1
    cout << endl;

    cout << "Tree : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << endl;
    cout << "Brute Force \nThe diameter of given tree is : ";
    cout << diameter(root) << endl; // O(n^2) time complexity
    cout << "Efficient \nThe diameter of given tree is : ";
    cout << diameterFast(root).first << endl; // O(n) time complexity
    return 0;
}