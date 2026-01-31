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

    void bfs(int start, vector<int> adj[], int V)
    {
        queue<int> q;
        vector<int> visited(V, false);
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            visited[node] = true;

            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
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

    s.bfs(0, adj, V);

    return 0;
}