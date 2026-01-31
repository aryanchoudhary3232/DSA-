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

    bool cycle_check_bfs(int start, vector<int> adj[], int V)
    {
        queue<int> q;
        vector<bool> visited(V+1, false);
        q.push(start);
        visited[start] = true;

        unordered_map<int, int> parent;
        parent[start] = -1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                    parent[i] = node;
                }
                if (visited[i])
                {
                    if (parent[node] != i)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    int V = 3;
    vector<int> adj[V+1];
    Solution s;

    s.addEdge(1,2,adj);
    s.addEdge(1,3,adj);

    s.printGraph(adj, V);

    cout<<s.cycle_check_bfs(1,adj,V);
    return 0;
}