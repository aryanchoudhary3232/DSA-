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

    void printGraph(vector<int> adj[], int V)
    {
        for (int i = 1; i <= V; i++)
        {
            cout << i << "->";
            for (auto ele : adj[i])
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    bool cycle_check_dfs(int node, vector<int> adj[], vector<bool> &visited, int parent)
    {
        cout << node << "->";
        visited[node] = true;

        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                if (cycle_check_dfs(adjacentNode, adj, visited, node))
                {
                    return true;
                }
            }
            else
            {
                if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool check_undirected(vector<int> adj[], int V)
    {
        vector<bool> visited(V + 1, false);

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                if (cycle_check_dfs(i, adj, visited, -1))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int V = 6;
    vector<int> adj[V + 1];
    Solution s;

    s.addEdge(1, 2, adj);
    s.addEdge(1, 3, adj);
    s.addEdge(4, 5, adj);
    s.addEdge(5, 6, adj);
    // s.addEdge(4, 6, adj);

    s.printGraph(adj, V);

    cout << s.check_undirected(adj, V);
    return 0;
}