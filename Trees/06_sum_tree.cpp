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
int sumCalc(node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumCalc(root->left) + sumCalc(root->right);
}
bool isSumTree(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    int l = sumCalc(root->left);
    int r = sumCalc(root->right);
    int total = l + r;
    if (root->data == total)
    {
        if (isSumTree(root->left) && isSumTree(root->right))
            return true;
    }
    return false;
}

// Fast and efficient approach
pair<bool, int> isSumTreeFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool sumcheck = root->data == leftAns.second + rightAns.second;
    pair<bool, int> ans;
    if (leftAns.first && rightAns.first && sumcheck)
    {
        ans.first = true;
        ans.second = 2 * root->data;
        // ans.second = root->data + leftAns.second + rightAns.second;
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

    // data1 : 1 3 -1 7 -1 -1 5 6 -1 -1 8 -1 -1  --> not a sum tree
    // data2 : 3 1 -1 -1 2 -1 -1 --> sum tree
    cout << endl;

    cout << "Tree : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << endl;
    // if (isSumTree(root))
    // {
    //     cout << "Sum Tree" << endl;
    // }
    // else
    // {
    //     cout << "Not a Sum Tree" << endl;
    // }
    if (isSumTreeFast(root).first)
    {
        cout << "Sum Tree" << endl;
    }
    else
    {
        cout << "Not a Sum Tree" << endl;
    }
    return 0;
}