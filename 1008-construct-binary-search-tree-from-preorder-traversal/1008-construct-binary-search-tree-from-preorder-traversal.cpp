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
    TreeNode* solve(int i, int n, vector<int> pre){
        if(i > n){
            return 0;
        }
        if(i == n){
            return new TreeNode(pre[i]);
        }
        
        TreeNode* root = new TreeNode(pre[i]);
        int idx = n;
        for(int j = i+1; j<=n; ++j){
            if(pre[j] > pre[i]){
                idx = j-1;
                break;
            }
        }
        TreeNode* left = solve(i+1, idx, pre);
        TreeNode* right = solve(idx+1,n,pre);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return solve(0, pre.size() -1, pre);
    }
};