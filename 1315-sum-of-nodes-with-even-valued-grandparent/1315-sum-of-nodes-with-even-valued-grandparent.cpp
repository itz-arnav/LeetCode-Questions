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
    int ans = 0;
    void solve(TreeNode* root, TreeNode* baap, TreeNode* dadaji){
        if(root == 0)
            return;
        if(dadaji and dadaji->val %2 == 0){
            ans += root->val;
        }
        if(root->left){
            solve(root->left, root, baap);
        }
        if(root->right){
            solve(root->right, root, baap);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root, 0, 0);
        return ans;
    }
};