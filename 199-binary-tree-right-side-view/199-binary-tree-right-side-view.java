/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
    List<Integer> list = new ArrayList<Integer>();
    if(root == null){
        return list;
    }
    
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    
    while(!queue.isEmpty()){
        int size = queue.size();
        list.add(queue.peek().val);
        for(int i = 0; i < size; i++){
            TreeNode curr = queue.poll();
            if(curr.right != null){
                queue.add(curr.right);
            }
            if(curr.left != null){
                queue.add(curr.left);
            }
        }
    }
    return list;
}
}