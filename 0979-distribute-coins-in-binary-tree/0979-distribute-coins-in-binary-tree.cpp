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
    int dfs(TreeNode* r, int &moves) {
  if (r == 0) return 0;
  int left = dfs(r->left, moves), right = dfs(r->right, moves);
  moves += abs(left) + abs(right);
  return r->val + left + right - 1;
}
int distributeCoins(TreeNode* r, int moves = 0) {
  dfs(r, moves);
  return moves;
}
};