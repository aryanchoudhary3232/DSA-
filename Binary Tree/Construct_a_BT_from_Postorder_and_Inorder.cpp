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
    TreeNode *buildTree(int is, int ie, int ps, int pe, vector<int> &inorder, vector<int> &postorder, map<int, int> &mp)
    {
        if (is > ie || ps > pe)
        {
            return nullptr;
        }
        int value = postorder[pe];
        TreeNode* root = new TreeNode(value);
        int inRoot = mp[value];
        int numsLeft = inRoot-is;

        root->left = buildTree(is, inRoot-1, ps, ps+numsLeft-1, inorder, postorder, mp);
        root->right = buildTree(inRoot+1, ie, ps+numsLeft, pe-1, inorder, postorder, mp);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode *root = buildTree(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder, mp);

        return root;
    }
};

void printInorder(TreeNode *root)
{
    if(root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution s;
    TreeNode *root = s.buildTree(inorder, postorder);

    printInorder(root);
    return 0;
}