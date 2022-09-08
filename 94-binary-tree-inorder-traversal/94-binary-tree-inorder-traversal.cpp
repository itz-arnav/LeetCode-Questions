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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == 0)
            return ans;
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true){
            
            if(node != 0){
                st.push(node);
                node = node->left;
            }
            else{
                if(!st.empty()){
                    node = st.top();
                    st.pop();
                    ans.push_back(node->val);
                    node = node->right;
                    
                }
                else{
                    break;
                }
            }
        }
        return ans;
        
    }
};