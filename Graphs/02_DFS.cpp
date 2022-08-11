#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int node1, int node2, bool direction)
    {
        adj[node1].push_back(node2);
        if (!direction)
            adj[node2].push_back(node1);
    }
    void printAdjList()
    {
        for (auto it : adj)
        {
            cout << it.first << " -> ";
            for (auto j : it.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
signed main()
{
    graph g;
    int node, edge;
    cout << "Enter number of nodes : ";
    cin >> node;
    cout << "Enter number of edges : ";
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);
    }
    return 0;
}