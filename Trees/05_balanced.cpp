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
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

// O(n^2) -- TIme Complexity
bool isBalanced(node *root)
{
    if (root == NULL)
        return true;
    if (isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1)
        return true;
    return false;
}

// efficient -- O(n)
pair<bool, int> isBalancedFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;

    bool bal = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && bal)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
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

    // data1 : 1 3 -1 7 -1 -1 5 6 -1 -1 8 -1 -1

    // data2 : 1 10 5 -1 -1 -1 39 -1 -1 //  balanced tree
    // data3 : 1 10 5 -1 -1 -1 -1 //  unbalanced tree
    cout << endl;

    cout << "Tree : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << endl;

    // Bruteforce -- O(n^2)
    if (isBalanced(root))
        cout << "Balanced" << endl;
    else
        cout << "Unbalanced" << endl;

    if (isBalancedFast(root).first)
        cout << "Balanced" << endl;
    else
        cout << "Unbalanced" << endl;

    return 0;
}