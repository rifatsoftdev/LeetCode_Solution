from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __inorder(self, root: Optional[TreeNode], ans:  List[int]):
        if (root == None):
            return

        self.__inorder(root.left, ans)
        ans.append(root.val)
        self.__inorder(root.right, ans)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.__inorder(root, ans)
        return ans


if __name__ == "__main__":
    solution = Solution()

    root1 = TreeNode(1)
    root1.right = TreeNode(2)
    root1.right.left = TreeNode(3)

    print(solution.inorderTraversal(root1))