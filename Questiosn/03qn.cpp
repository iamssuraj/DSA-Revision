// kth max and min
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int a[n];
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    int k;
    cin >> k;
    int j = 0;
    int end = n-1;
    for (auto i : s)
    {
        if (j == k - 1)
            cout << i << endl; // kth smallest
        if(end == k-1)
            cout << i << endl; // kth largest
        j++;
        end--;
    }
    return 0;
}