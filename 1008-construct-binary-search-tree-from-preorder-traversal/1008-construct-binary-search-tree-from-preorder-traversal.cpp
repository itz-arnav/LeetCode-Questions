
class Solution {
public:
     TreeNode* solve(vector<int>&preorder,int s, int e){
        if(s > e){
            return 0;
        }
         if(s == e){
             TreeNode* root = new TreeNode(preorder[s]);
             return root;
         }
        int left_most_data = preorder[s];
         
        int left_half_end = e;
        int right_half_start = e+1;
         
        for(int i= s+1; i<=e ;i++){
            if(preorder[i] > left_most_data){
                left_half_end = i-1;
                right_half_start = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(left_most_data);
        root->left=solve(preorder,s+1, left_half_end);
        root->right= solve(preorder,right_half_start,e);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* ans = solve(preorder,0,preorder.size()-1);   
        return ans; 
    }
};