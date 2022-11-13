#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

signed main()
{
    int k;
    cout << "Enter 10 elements : " << endl;
    vector<int> v(10);
    for (int i = 0; i < 10; i++)
        cin >> v[i];
    cout << "Enter k : ";
    cin >> k;

    // Solution - 1
    // priority_queue<int> pq;
    // for(auto it:v)
    //     pq.push(it);
    // while(--k)
    // {
    //     pq.pop();
    // }
    // cout << pq.top() << endl;

    // Solution - 2
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    while (i < k)
    {
        pq.push(v[i++]);
    }
    for (int i = k; i < v.size(); i++)
    {
        if (v[i] > pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
    return 0;
}