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
    void solve(TreeNode* root, vector<int> &ans){
        if(root == 0)
            return;
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }
    TreeNode* help(int i, int n, vector<int> &ans){
        if(i == n){
            TreeNode* temp = new TreeNode(ans[i]);
            return temp;
        }
        if(i > n){
            return 0;
        }
        int mid = i + (n-i)/2;
        TreeNode* head = new TreeNode(ans[mid]);
        head->left = help(i, mid-1, ans);
        head->right = help(mid+1,n,ans);
        return head;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> ans;
        solve(root, ans);
        return help(0, ans.size()-1, ans);
    }
};