from typing import List, Optional
from devlibs.binary_tree import TreeNode, PreOrderTraversals


class Solution:
    def createBinaryTree(self, descriptions):
        nodes = {}
        children = set()

        for parent, child, isLeft in descriptions:

            if parent not in nodes:
                nodes[parent] = TreeNode(parent)

            if child not in nodes:
                nodes[child] = TreeNode(child)

            if isLeft:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]

            children.add(child)

        for val in nodes:
            if val not in children:
                return nodes[val]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    descriptions1 = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    output1 = solution.createBinaryTree(descriptions1)
    result1 = []
    PreOrderTraversals(output1, result1)
    print(result1)

    # test cases 2
    descriptions2 = [[1,2,1],[2,3,0],[3,4,1]]
    output2 = solution.createBinaryTree(descriptions2)
    result2 = []
    PreOrderTraversals(output2, result2)
    print(result2)
    