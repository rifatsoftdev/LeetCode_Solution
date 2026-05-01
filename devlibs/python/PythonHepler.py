from typing import List, Optional

from binarytree import TreeNode
# from linkedlist import .


class PythonHepler:
    def __buildBST(self, nums: List[int], left: int, right: int):
        if (left > right):
            return None
        
        mid = left + (right - left) / 2
        node = TreeNode(nums[mid])
        
        node.left = self.__buildBST(nums, left, mid - 1)
        node.right = self.__buildBST(nums, mid + 1, right);
        
        return node

    def list2BST(self, nums: List[int]):
        nums.sort()
        return self.__buildBST(nums, 0, len(nums)-1)
    
    def printSinglyLinkList(self) -> None:
        pass