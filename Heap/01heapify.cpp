#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

class heap
{
    public:
    vector<int> v;
    int index;
    heap()
    {
        index = 0;
        v.push_back(-1);
    }
    void push(int data)
    {
        v.push_back(data);
        index++;
        while(index > 1)
        {
            int parent = index/2;
            if(v[parent] < v[index])
                swap(v[parent], v[index]);
            else
                return ;
        }
    }
    void pop()
    {
        v[1] = v[v.size()-1];
        v.pop_back();
        int i = 1;
        while(i < v.size())
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if(leftIndex < v.size() && v[i] < v[leftIndex])
            {
                swap(v[i], v[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < v.size() && v[i] < v[rightIndex])
            {
                swap(v[i], v[rightIndex]);
                i = rightIndex;
            }
            else return ;
        }
    }
    void print()
    {
        for(int i=1;i<v.size();i++)
        {
            cout << v[i] << " ";
        }
    }
};
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
signed main()
{
    vector<int> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    int n = v.size();
    for(int i=n/2;i>0;i--)
    {
        heapify(v, n, i); 
    }
    for(int i=1;i<v.size();i++)
        cout << v[i] << " " ;
    return 0;
}