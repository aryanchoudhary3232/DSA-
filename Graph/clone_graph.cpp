#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> mp;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (mp.find(node) != mp.end())
        {
            return mp[node];
        }

        Node *clone = new Node(node->val);
        mp[node] = clone;

        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }

    void printGraph(Node *node)
    {
        queue<Node *> q;
        unordered_set<Node *> vis;

        q.push(node);
        vis.insert(node);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            cout << front->val << "->";
            for (Node *neighbor : front->neighbors)
            {
                cout << neighbor->val << " ";
                if (vis.find(neighbor) == vis.end())
                {
                    vis.insert(neighbor);
                    q.push(neighbor);
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution s;
    Node *clone = s.cloneGraph(n1);
    s.printGraph(clone);

    return 0;
}