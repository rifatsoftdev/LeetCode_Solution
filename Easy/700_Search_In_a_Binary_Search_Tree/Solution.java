

public class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        TreeNode curr = root;

        while (curr != null) {
            if (curr.val == val) {
                return curr;
            } else if (curr.val < val) {
                curr = curr.right;
            } else {
                curr = curr.left;
            }
        }

        return null;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);

        root.left = new TreeNode(2);
        root.right = new TreeNode(7);

        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        Solution solution = new Solution();

        // test cases 1
        TreeNode result1 = solution.searchBST(root, 2);
        System.out.println(result1.val);

        // test cases 2
        TreeNode result2 = solution.searchBST(root, 5);
        System.out.println(result2);

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