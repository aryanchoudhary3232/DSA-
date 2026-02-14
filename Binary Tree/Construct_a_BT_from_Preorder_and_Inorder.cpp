#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *recursion(int preorderLeft, int preorderRight, int inorderLeft, int inorderRight, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp)
    {
        int value = preorder[preorderLeft];

        TreeNode *root = new TreeNode(value);

        if (preorderLeft > preorderRight || inorderLeft > inorderRight)
        {
            return NULL;
        }

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inorderLeft;

        root->left = recursion(preorderLeft + 1, preorderLeft + numsLeft, inorderLeft, inRoot - 1, preorder, inorder, mp);
        root->right = recursion(preorderLeft + numsLeft + 1, preorderRight, inRoot + 1, inorderRight, preorder, inorder, mp);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode *root = recursion(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, mp);

        return root;
    }
};

void printInorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    printInorder(root);

    return 0;
}