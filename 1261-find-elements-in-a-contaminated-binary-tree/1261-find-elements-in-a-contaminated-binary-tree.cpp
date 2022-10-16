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
class FindElements {
public:
    unordered_map<int,int> mp;
    FindElements(TreeNode* root) {
        solve(root, 0);
    }
    void solve(TreeNode* root, int x){
        if(root == 0)
            return;
        mp[x]=1;
        if(root->left)
        solve(root->left, 2*x + 1);
        if(root->right)
        solve(root->right, 2*x +2);
    }
    bool find(int target) {
        // for(auto x : mp){
        //     cout<<x.first<<endl;
        // }
        return mp[target] > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */