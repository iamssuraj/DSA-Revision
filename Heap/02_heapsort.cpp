#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int left = 2*i, right = 2*i + 1;
    if(left < n && v[largest] < v[left])
        largest = left;
    if(right < n && v[largest] < v[right])
        largest = right;
    
    if(largest != i)
    {
        swap(v[largest], v[i]);
        heapify(v, n, largest);
    }
}

void heapSort(vector<int> &v)
{
    int n = v.size();
    while(n > 1)
    {
        swap(v[n-1], v[1]);
        n--;
        heapify(v, n, 1);
    }
}

signed main()
{
    vector<int> v;
    v.push_back(-1);
    v.push_back(16);
    v.push_back(24);
    v.push_back(13);
    v.push_back(04);
    v.push_back(11);
    v.push_back(60);
    v.push_back(17);
    int n = v.size();
    for(int i=n/2;i>0;i--)
    {
        heapify(v, n, i); 
    }
    heapSort(v);
    for(int i=1;i<v.size();i++)
        cout << v[i] << " " ;
    return 0;
}