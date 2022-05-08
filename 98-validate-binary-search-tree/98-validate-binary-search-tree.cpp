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
    long curr = INT_MIN-500L;
    bool flag = true;
    void solve(TreeNode* root){
        if(root == 0)
            return;
        solve(root->left);
        long c = root->val;
        if(c <= curr)
            flag = false;
        curr = root->val;
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        
        return flag;
    }
};