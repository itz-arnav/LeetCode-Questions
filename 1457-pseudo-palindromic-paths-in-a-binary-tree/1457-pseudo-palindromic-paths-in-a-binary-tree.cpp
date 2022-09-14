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
    int get(TreeNode* root, int mask){
        if(root == NULL)return 0;
        // if root->val has occured odd times set to even times
        // else if root->val has occured even times set to odd times
        int k = 1 << root->val;
        mask = mask ^ k;
        
        if(root->left == NULL && root->right == NULL){
            // if leaf node check how many numbers has occured odd times
            // if odd occurence are zero or one return true else false
            if(mask == 0)return 1;
            mask = mask & (mask-1);
            if(mask == 0)return 1;
            return 0;
        }
        
        return get(root->left, mask) + get(root->right, mask) ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int mask = 0;
        // zero means every number has occured even times
      return  get(root, mask);
    }
};