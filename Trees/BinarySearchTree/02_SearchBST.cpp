#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node* insertBST(node* root, int data)
{
    if(root == NULL)
    {
        node* p = new node(data);
        return p;
    }
    if(data > root->data)
    {
        root->right = insertBST(root->right, data);
    }
    else
    {
        root->left = insertBST(root->left, data);
    }
}
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
bool SearchBST(node* root, int val)
{
    // if(root == NULL)
    // {
    //     return false;
    // }
    // if(root->data == val)
    //     return true;
    // else if(val > root->data)
    // {
    //     return SearchBST(root->right, val);
    // }   
    // else
    // {
    //     return SearchBST(root->left, val);
    // }


    // iterative 

    node* temp = root;
    while(temp)
    {
        if(temp->data == val)
        {
            return true;
        }
        else if(val > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return false;
}
signed main()
{
    int data;
    node* root = NULL;
    cout << "Enter data for insertion \n";
    // 5 18 7 1 2 3 4 16 -1
    cin >> data;
    while(data!=-1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
    root = insertBST(root, 15);
    levelOrderTraversal(root);
    cout << SearchBST(root, 5) << endl; // 1
    cout << SearchBST(root, 15) << endl; // 0
    cout << SearchBST(root, 18) << endl; // 1
    cout << SearchBST(root, 16) << endl; // 1
    return 0;
}