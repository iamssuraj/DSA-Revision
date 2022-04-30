// Union and intersection of two arrays
#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n1, n2;
    cin >> n1 >> n2;  // size of 2 arrays
    int a[n1], b[n2]; // declaring 2 arrays
    set<int> s1, s2;  // 2 sets
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
        s1.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
        s2.insert(b[i]);
    }
    set<int> uni;
    set<int>::iterator it;
    for (it = s1.begin(); it != s1.end(); it++)
    {
        uni.insert(*it);
    }
    for (it = s2.begin(); it != s2.end(); it++)
    {
        uni.insert(*it);
    }
    for (it = uni.begin(); it != uni.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    return 0;
}