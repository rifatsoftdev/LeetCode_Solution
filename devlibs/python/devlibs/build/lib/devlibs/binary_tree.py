from typing import Optional, List



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def ListToBinaryTree(nums: list[int]) -> TreeNode:
    if not nums:
        return None

    root = TreeNode(nums[0])
    queue = [root]
    i = 1

    while i < len(nums):
        curr = queue.pop(0)

        if i < len(nums) and nums[i] is not None:
            curr.left = TreeNode(nums[i])
            queue.append(curr.left)
        i += 1

        if i < len(nums) and nums[i] is not None:
            curr.right = TreeNode(nums[i])
            queue.append(curr.right)
        i += 1

    return root


def InOrderTraversals(root: TreeNode, result: List) -> List:
    if not root:
        return result
    
    InOrderTraversals(root.left, result)
    result.append(root.val)
    InOrderTraversals(root.right, result)

    return result


def PreOrderTraversals(root: TreeNode, result: List) -> List:
    if not root:
        return result
    
    result.append(root.val)
    PreOrderTraversals(root.left, result)
    PreOrderTraversals(root.right, result)

    return result


def PostOrderTraversals(root: TreeNode, result: List) -> List:
    if not root:
        return result
    
    PostOrderTraversals(root.left, result)
    PostOrderTraversals(root.right, result)

    result.append(root.val)

    return result


def LevelOrderTraversal(root: TreeNode, result: List) -> List:
    if not root:
        return []

    queue = [root]
    while queue:
        node = queue.pop(0)
        if node:
            result.append(node.val)
            if node.left or node.right or any(q is not None for q in queue):
                queue.append(node.left)
                queue.append(node.right)
        else:
            result.append(None)

    # Remove trailing None values to match standard representation
    while result and result[-1] is None:
        result.pop()

    return result

