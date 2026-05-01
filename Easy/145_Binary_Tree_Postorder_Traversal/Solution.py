from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __postorder(self, node: Optional[TreeNode], result: List[int]) -> None:
        if not node:
            return
        
        self.__postorder(node.left, result)
        self.__postorder(node.right, result)
        result.append(node.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        result = []
        self.__postorder(root, result)

        return result


if __name__ == "__main__":
    pass