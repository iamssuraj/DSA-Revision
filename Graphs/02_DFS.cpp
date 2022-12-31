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
void DFS(unordered_map<int, list<int>> adjList, unordered_map<int, bool> &visited, int start_node)
{
    stack<int> st;
    st.push(start_node);
    visited[start_node] = true;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        cout << top << " "; // can be stored into a vector and returned
        for (auto it : adjList[top])
        {
            if (!visited[it])
            {
                st.push(it);
                visited[it] = true;
            }
        }
    }
}
signed main()
{
    graph g;
    int node, edge;
    cout << "Enter number of nodes : ";
    cin >> node;
    cout << "Enter number of edges : ";
    cin >> edge;
    unordered_map<int, bool> visited;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);
        visited.insert({u, false});
        visited.insert({v, false});
    }
    unordered_map<int, list<int>> adjList = g.adj;
    cout << "Breadth First Search would look like : ";
    // int first = adjList.begin()->first;
    for(auto it:visited)
    {
        if(!it.second)
            DFS(adjList, visited, it.first);
    }
    cout << endl;
    return 0;
}