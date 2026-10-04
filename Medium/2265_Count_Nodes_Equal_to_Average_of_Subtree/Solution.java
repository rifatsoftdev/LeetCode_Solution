import java.util.*;


public class Solution {
    int count = 0;

    public int[] dfs(TreeNode node) {
        if (node == null) {
            return new int[]{0, 0}; // {sum, count}
        }

        int[] left = dfs(node.left);
        int[] right = dfs(node.right);

        int sum = left[0] + right[0] + node.val;
        int cnt = left[1] + right[1] + 1;

        if (node.val == sum / cnt) {
            count++;
        }

        return new int[]{sum, cnt};
    }

    public int averageOfSubtree(TreeNode root) {
        count = 0;
        dfs(root);
        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        // test cases 2
        
        
    }
}


// Definition for a binary tree node.
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