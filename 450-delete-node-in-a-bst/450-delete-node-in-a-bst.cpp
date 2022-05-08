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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == 0)
            return root;
        if(root->val == key)
        {
            TreeNode* left = root->left;
            TreeNode* right=  root->right;
            TreeNode* temp = root->left;
            while(temp and temp->right != 0){
                temp = temp->right;
            }
            if(temp)
            temp->right = right;
            if(left)
                return left;
            else
                return right;
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        else{
            root->left = deleteNode(root->left, key);
            return root;
        }
    }
};