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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        return MBST(nums, 0, nums.size() - 1);
    }
    TreeNode* MBST(vector<int>& nums, int low, int high){
        if(low > high){
            return 0;
        }
        int mid = low + (high - low)/2;
        auto root = new TreeNode(nums[mid]);
        root->left = MBST(nums, low, mid-1);
        root->right = MBST(nums, mid+1, high);
        return root;
        
        
    }
    
};