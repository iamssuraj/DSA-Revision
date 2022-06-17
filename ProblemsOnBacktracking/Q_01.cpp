// find all permutations of an input string
#include <bits/stdc++.h>
using namespace std;
#define int long long int
string swap(string s, int a, int b)
{
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
    return s;
}
void permutations(string s, int left, int right)
{
    if (left == right)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            s = swap(s, left, i);
            permutations(s, left + 1, right);
            s = swap(s, left, i);
        }
    }
}
signed main()
{
    string s;
    cout<<"Enter a string : ";
    cin >> s;
    permutations(s, 0, s.size() - 1);
    return 0;
}