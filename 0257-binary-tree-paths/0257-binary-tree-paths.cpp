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
    void solve(TreeNode* root, vector<string>&ans, string temp){
        if(root == 0)
            return;
        if(root->left == NULL && root->right==NULL){
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        if(root->left)
            solve(root->left,ans,temp +to_string(root->val) +"->" );
        if(root->right)
            solve(root->right,ans,temp + to_string(root->val) + "->");

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL)
            return ans;
        string temp = "";
        solve(root,ans,temp); 
        return ans;   
    }
};