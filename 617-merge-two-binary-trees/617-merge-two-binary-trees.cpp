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
    TreeNode* mergeTrees(TreeNode* a, TreeNode* b) {
        if(a == 0 and b == 0)
            return a;
        if(a == 0 and b != 0)
            return b;
        else if(a != 0 and b== 0)
            return a;


        a->val += b->val;
        if(a->left)
        mergeTrees(a->left, b->left);
        else if(b->left){
            a->left = b->left;
        }
        if(a->right)
        mergeTrees(a->right, b->right);
        else if(b->right){
            a->right = b->right;
        }
        return a;
    }
};