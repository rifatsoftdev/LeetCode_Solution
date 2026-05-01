from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        curr = root

        while (curr != None):
            if (curr.val == val):
                return curr
            elif (curr.val < val):
                curr = curr.right
            else:
                curr = curr.left
        
        return None


if __name__ == "__main__":
    root = TreeNode(4)

    root.left = TreeNode(2)
    root.right = TreeNode(7)

    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)

    solution = Solution()

    # test cases 1
    print(solution.searchBST(root, 2).val)

    # test cases 2
    print(solution.searchBST(root, 5))