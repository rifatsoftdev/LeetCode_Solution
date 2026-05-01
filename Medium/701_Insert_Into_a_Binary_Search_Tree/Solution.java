

public class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode treeNode = new TreeNode(val);

        if (root == null) {
            return treeNode;
        }

        TreeNode curr = root;

        while (curr != null) {
            if (curr.val < val) {
                if (curr.right == null) {
                    curr.right = treeNode;
                    break;
                } else {
                    curr = curr.right;
                }
            } else {
                if (curr.left == null) {
                    curr.left = treeNode;
                    break;
                } else {
                    curr = curr.left;
                }
            }
        }

        return root;
    }

    public static void main(String[] args) {
        

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