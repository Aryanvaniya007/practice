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
    int target;
    public boolean hasPathSum(TreeNode root, int targetSum) {
        target = targetSum;
        return Helper(root,0);
    }
    private boolean Helper(TreeNode root, int sum)
    {
        if(root == null)
        {
            return false;
        }
        sum += root.val;
        if(root.left==null && root.right==null)
            return sum==target;
        boolean lans = Helper(root.left,sum);
        boolean rans = Helper(root.right,sum);
        return lans||rans;
    }
}