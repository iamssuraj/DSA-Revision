//Reverse Array
#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k = n-1;
    int i = 0;
    while(i<k)
    {
        int t = a[k];
        a[k] = a[i];
        a[i] = t;
        i++;
        k--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}