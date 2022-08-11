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
void BFS(unordered_map<int, list<int>> adjList, unordered_map<int, bool> &visited, int start_node)
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " "; // can be stored into a vector and returned
        for (auto it : adjList[front])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
signed main()
{
    graph g;
    int edge;
    cout << "Enter number of edges : ";
    cin >> edge;
    unordered_map<int, bool> visited;
    cout << "Enter connections : Node1 -- Node2 " << endl;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false); // undirected
        visited.insert({u, false});
        visited.insert({v, false});
    }
    unordered_map<int, list<int>> adjList = g.adj;
    cout << "Breadth First Search would look like : ";
    // int first = adjList.begin()->first;
    for(auto it:visited)
    {
        if(!it.second)
            BFS(adjList, visited, it.first);
    }
    cout << endl;
    // g.printAdjList();
    return 0;
}