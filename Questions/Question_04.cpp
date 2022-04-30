#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int a[n];
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            count0++;
        else if (a[i] == 1)
            count1++;
        else
            count2++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < count0)
            a[i] = 0;
        else if (i < count0 + count1)
            a[i] = 1;
        else
            a[i] = 2;
        cout << a[i] << " ";
    }

    return 0;
}