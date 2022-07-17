#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
int EuclideanGCD(int a, int b)
{
    // if (b == 0)
    //     return a;
    // return EuclideanGCD(b, a % b);

    return a%b ? EuclideanGCD(b, a%b) : b;
}
signed main()
{
    int a, b;
    cin >> a >> b;
    cout << EuclideanGCD(a, b) << endl;
    return 0;
}