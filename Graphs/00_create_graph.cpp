#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
class graph
{
public:
    unordered_map<int, vector<int>> adj;
    void addEdge(int edge1, int edge2, bool direction)
    {
        // if direction is true, graph is directed, otherwise, graph is undirected
        adj[edge1].push_back(edge2);
        if (!direction)
            adj[edge2].push_back(edge1);
    }
    void printGraph()
    {
        // for (auto it1 : adj)
        // {
        //     cout << it1.first << "--> ";
        //     for (auto it2 : it1.second)
        //         cout << it2 << " & ";
        //     cout << endl;
        // }
        for(auto it:adj)
        {
            cout << it.first << "--> ";
            for(int i=0;i<it.second.size();i++)
            {
                cout << it.second[i] << " ";
            }
            cout << endl;
        }
    }
};
signed main()
{
    graph g;
    int n, e;
    cout << "Enter no. of nodes : ";
    cin >> n;

    cout << "Enter no. of edges : ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g.addEdge(t1, t2, 0);
    }
    g.printGraph();
    return 0;
}