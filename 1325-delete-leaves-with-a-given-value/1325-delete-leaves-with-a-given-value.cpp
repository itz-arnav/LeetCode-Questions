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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == 0)
            return 0;
        if(root->left == 0 and root->right == 0 and root->val == target){
            return 0;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if(root->left == 0 and root->right == 0 and root->val == target){
            return 0;
        }
        return root;
    }
};