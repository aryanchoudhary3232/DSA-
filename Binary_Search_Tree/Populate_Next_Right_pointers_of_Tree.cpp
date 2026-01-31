#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
private:
    void nextPointer(Node *root)
    {
        if (!root->left)
        {
            return;
        }
        if (root->left)
        {
            root->left->next = root->right;
        }
        if (root->next)
        {
            root->right->next = root->next->left;
        }

        nextPointer(root->left);
        nextPointer(root->right);
    }

public:
    Node *connect(Node *root)
    {
        if(root == NULL) return root;
        nextPointer(root);

        return root;
    }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    Node* solu = s.connect(root);
    cout<<solu->val<<endl;
    cout<<solu->left->val<<endl;
    cout<<solu->left->left->val<<endl;
    cout<<solu->left->right->val<<endl;
    cout<<solu->right->val<<endl;
    cout<<solu->right->left->val<<endl;
    cout<<solu->right->right->val<<endl;

    cout<<"Solution:"<<endl;
    cout<<solu->left->next->val<<endl;
    cout<<solu->left->left->next->val<<endl;
    cout<<solu->left->left->next->next->val<<endl;
    cout<<solu->right->left->next->val<<endl;

    return 0;
}