#include <bits/stdc++.h>
using namespace std;
// void sieve_of_eratosthenes(int n)
// {
//     // int prime[100] = {0};
//     vector<int> prime(n + 1, 0);
//     for (int i = 2; i * i <= n; i++) // i<=n generally, but to optimize i*i <= n
//     {
//         if (prime[i] == 0)
//         {
//             for (int j = i * i; j <= n; j += i)
//                 prime[j] = 1;
//         }
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         if (prime[i] == 0)
//             cout << i << endl;
//     }
// }

// bool array is even more better
void sieve_of_eratosthenes(int n)
{
    // int prime[100] = {0};
    vector<bool> prime(n + 1, false);
    for (int i = 2; i * i <= n; i++) // i<=n generally, but to optimize i*i <= n
    {
        if (prime[i] == false)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = true;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == false)
            cout << i << endl;
    }
}

signed main()
{
    int n;
    cin >> n;
    sieve_of_eratosthenes(n);
    return 0;
}