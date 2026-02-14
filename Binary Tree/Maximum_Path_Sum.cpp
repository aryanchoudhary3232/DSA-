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
    int postorder(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = postorder(root->left, ans);
        if(left<0) left = 0;
        int right = postorder(root->right, ans);
        if(right<0) right = 0;
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        postorder(root, ans);

        return ans;
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(-1);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    Solution s;
    cout<<s.maxPathSum(root);

    return 0;
}
