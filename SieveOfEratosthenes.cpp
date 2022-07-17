#include <bits/stdc++.h>
using namespace std;
// void sieve_of_eratosthenes(int n)
// {
//     // int prime[100] = {0};
//     vector<int> prime(n + 1, 1);
//     for (int i = 2; i * i <= n; i++) // i<=n generally, but to optimize i*i <= n
//     {
//         if (prime[i] == 1)
//         {
//             for (int j = i * i; j <= n; j += i)
//                 prime[j] = 0;
//         }
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         if (prime[i] == 1)
//             cout << i << endl;
//     }
// }

// bool array is even more better
void sieve_of_eratosthenes(int n)
{
    // int prime[100] = {0};
    vector<bool> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++) // i<=n generally, but to optimize i*i <= n
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == true)
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