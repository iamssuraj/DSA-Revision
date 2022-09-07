#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
vector<vector<int>> v;
void printSubsets(vi &a, int i, vi &subset)
{
    if(i == a.size())
    {
        v.push_back(subset);
        return ;
    }
    printSubsets(a, i+1, subset);
    subset.push_back(a[i]);
    printSubsets(a, i+1, subset);
    subset.pop_back();
}
signed main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vi a(n);
    rep(i,0,n)
        cin >> a[i];
    vi subset;
    printSubsets(a, 0, subset);
    for(auto it:v)
    {
        for(auto it2:it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}