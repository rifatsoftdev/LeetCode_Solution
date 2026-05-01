import java.util.ArrayList;
import java.util.List;


class Solution {
    private static void inorder(TreeNode root, List<Integer> ans) {
        if (root == null) {
            return;
        }
        
        inorder(root.left, ans);
        ans.add(root.val);
        inorder(root.right, ans);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        inorder(root, ans);
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNode root1 = new TreeNode(1);
        root1.right = new TreeNode(2);
        root1.right.left = new TreeNode(3);

        System.out.println(solution.inorderTraversal(root1).toString());
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