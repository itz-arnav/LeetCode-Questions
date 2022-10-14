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
    int curr = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root == 0)
            return root;
        bstToGst(root->right);
        curr += root->val;
        root->val = curr;
        bstToGst(root->left);
        return root;
    }
};