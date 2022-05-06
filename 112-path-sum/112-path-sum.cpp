/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool s(TreeNode* root, int tar, int cur) {
        if(root == 0)
            return 0;
            if(root->left == 0 and root->right == 0)
            {
                cur += root->val;
                return cur == tar;
            }
        
        int x = root->val;
        cur = cur + x;
        bool ans1 = s(root->left, tar, cur);
        bool ans2 = s(root->right, tar, cur);
    return ans1 or ans2;
    
    }
    bool hasPathSum(TreeNode* root, int tar) {
        return s(root, tar, 0);
    
    }
};