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
        this->left = NULL;
        this->right = NULL;
    }
};

class LeftView
{
public:
    void leftViewBT(Node *node, int level, vector<int> &ans)
    {
        if (node == NULL)
        {
            return;
        }

        if (level == ans.size())
        {
            ans.push_back(node->val);
        }
        leftViewBT(node->left, level + 1, ans);
        leftViewBT(node->right, level + 1, ans);
        // leftViewBT(node->right, level + 1, ans);
        // leftViewBT(node->left, level + 1, ans);
    }
};

int main()
{
    Node *head = new Node(1);
    head->left = new Node(4);
    head->right = new Node(2);
    head->left->right = new Node(5);
    head->right->right = new Node(3);

    LeftView *lv = new LeftView();
    vector<int> ans;
    lv->leftViewBT(head, 0, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}