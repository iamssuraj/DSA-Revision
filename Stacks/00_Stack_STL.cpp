#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

signed main()
{
    //creation
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(0);
    s.pop();

    cout << s.top() << endl;
    // cout << s.empty() << endl; // -- boolean
    return 0;
}