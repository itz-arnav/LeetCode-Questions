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
    
    TreeNode* solve(int i, int n, vector<int>& nums){
        TreeNode* root = 0;
        if(i > n)
            return 0;
        if(i == n){
            root = new TreeNode(nums[i]);
            return root;
        }
        int idx = i;
        for(int j = i; j<=n; ++j){
            if(nums[j] > nums[idx]){
                idx = j;
            }
        }
        root = new TreeNode(nums[idx]);
        root->left = solve(i, idx-1, nums);
        root->right = solve(idx+1, n, nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};