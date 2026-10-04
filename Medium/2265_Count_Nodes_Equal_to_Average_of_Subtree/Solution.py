from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        count = 0

        def dfs(node):
            nonlocal count
            if not node:
                return 0, 0  # sum, count

            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)

            tree_sum = left_sum + right_sum + node.val
            tree_count = left_count + right_count + 1

            if node.val == tree_sum // tree_count:
                count += 1

            return tree_sum, tree_count

        dfs(root)
        
        return count


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    # test cases 2
    
    