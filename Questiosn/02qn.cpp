// Max Min
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    cout << "max = " << max << endl
         << "min = " << min;
    return 0;
}