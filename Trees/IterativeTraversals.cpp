#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
class node
{
public:
    node *left;
    node *right;
    int val;
    node(int val)
    {
        left = NULL;
        right = NULL;
        this->val = val;
    }
};
node *insert(node *root, int val)
{
    if (root == NULL)
    {
        node *p = new node(val);
        return p;
    }
    if (val > root->val)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);
    return root;
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
            cout << temp->val << " ";
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

void IterativeInorder(node *root)
{
    stack<node *> st;
    node *temp = root;
    while (true)
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
                break;
            temp = st.top();
            cout << temp->val << " ";
            st.pop();
            temp = temp->right;
        }
    }
}

void IterativePreOrder(node *root)
{
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
}

void IterativePostOrder(node *root)
{
    node *cur = root, *temp = NULL;
    stack<node *> st;
    while (cur || !st.empty())
    {
        if (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->val << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->val << " ";
                }
            }
            else
                cur = temp;
        }
    }
}

signed main()
{
    node *root = NULL;
    int n;
    cin >> n;
    while (n)
    {
        root = insert(root, n);
        cin >> n;
    }
    // 5 1 6 2 7 3 8 4 9 0
    cout << "LevelOrder : " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "PreOrder : " << endl;
    IterativePreOrder(root);
    cout << endl;

    cout << "InOrder : " << endl;
    IterativeInorder(root);
    cout << endl;

    cout << "PostOrder : " << endl;
    IterativePostOrder(root);
    cout << endl;

    return 0;
}