#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void bottomView(Node *root)
    {
        queue<pair<int, Node *>> q;
        q.push({0, root});
        map<int, Node *> mp;

        while (!q.empty())
        {
            pair<int, Node *> node = q.front();
            q.pop();

            mp[node.first] = node.second;

            if (node.second->left)
            {
                q.push({node.first - 1, node.second->left});
            }
            if (node.second->right)
            {
                q.push({node.first + 1, node.second->right});
            }
        }

        for (auto i : mp)
        {
            cout << i.second->val << " ";
        }
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(9);
    root->right->right = new Node(11);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);

    Solution s;
    s.bottomView(root);

    return 0;
}
