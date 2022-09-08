import java.util.*;

public class RecursiveSolution {

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





    List<Integer> result = new ArrayList<>();

    void dfs(TreeNode root) {
        if(root == null) return;

        dfs(root.left);
        result.add(root.val);
        dfs(root.right);
    }

    List<Integer> inorder(TreeNode root) {
        dfs(root);

        return result;
    }

	public static void main(String[] argv) {


 	} 	
}