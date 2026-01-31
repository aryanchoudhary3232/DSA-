#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void addEdge(int u, int v, vector<int> adj[])
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfsHelper(int start, vector<int> adj[], vector<bool> &visited)
    {
        cout << start << " ";
        visited[start] = true;

        for (auto i : adj[start])
        {
            if (!visited[i])
            {
                dfsHelper(i, adj, visited);
            }
        }
    }

    void dfs(int start, vector<int> adj[], int V)
    {
        vector<bool> visited(V, false);
        dfsHelper(start, adj, visited);
    }

    void printGraph(vector<int> adj[], int V)
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (auto ele : adj[i])
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V = 5;
    vector<int> adj[V];
    Solution s;
    s.addEdge(0, 1, adj);
    s.addEdge(0, 2, adj);
    s.addEdge(1, 3, adj);
    s.addEdge(2, 3, adj);
    s.addEdge(4, 3, adj);

    s.printGraph(adj, V);

    s.dfs(0, adj, V);

    return 0;
}