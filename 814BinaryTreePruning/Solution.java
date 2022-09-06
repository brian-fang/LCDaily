import java.util.*;


public class Solution {

    class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
        }
    }

    boolean shouldremove(TreeNode node) {
        if(node == null) return true;

        boolean removeleft = shouldremove(node.left);
        boolean removeright = shouldremove(node.right);

        // If this node does not belong
        if(removeleft && removeright && node.val == 0) return true;

        // This node belongs, but its subtrees may need to be pruned 
        if(removeleft) node.left = null;
        if(removeright) node.right = null;

        return false;
    }

    TreeNode prunetree(TreeNode root) {
        // Either the whole tree consists of 0's or is null - we need to remove everything+, in that case, just return null
        // Or the root is part of a tree that contains a 1 and should not be removed
        if(shouldremove(root)) return null;

        return root;
    }


	public static void main(String[] argv) {

 	} 	
}