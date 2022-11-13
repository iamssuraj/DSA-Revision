#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

signed main()
{
    priority_queue<int> pq; // internal max - heap
    for(int i=10;i>=-10;i--)    
        pq.push(i);
    pq.push(110);
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";

    cout << pq.empty() << endl;



    //min - heap
    priority_queue<int, vector<int>, greater<int>> min_pq; // internal max - heap
    for(int i=10;i>=-10;i--)    
        min_pq.push(i);
    min_pq.push(110);
    cout << min_pq.top() << " ";
    min_pq.pop();
    cout << min_pq.top() << " ";

    cout << min_pq.empty() << endl;

    return 0;
}