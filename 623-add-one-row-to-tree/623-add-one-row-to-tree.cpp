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
    TreeNode* solve(TreeNode* root, int val, int curr, int depth){
        if(root == 0)
            return root;
        if((curr + 1) == depth){
                TreeNode* temp = new TreeNode(val);
                if(root->left)
                temp->left = root->left;
                root->left = temp;
            
                temp = new TreeNode(val);
                if(root->right)
                temp->right = root->right;
                root->right = temp;
            
            return root;
        }
        solve(root->left, val,  curr+1, depth);
        solve(root->right, val,  curr+1, depth);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        return solve(root, val, 1, depth);
    }
};