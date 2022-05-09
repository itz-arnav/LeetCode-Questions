/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* root, TreeNode* cloned, TreeNode* target) {
        if(cloned == 0)
            return 0;
        if(cloned->val == target->val){
            return cloned;
        }
        else{
            TreeNode* left = getTargetCopy(root->left, cloned->left, target);
             TreeNode* right = getTargetCopy(root->right, cloned->right, target);
            if(left)
                return left;
            return right;
        }
    }
};