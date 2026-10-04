from typing import List, Optional


class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        ans = 0

        for i in operations:
            if ("++" in i):
                ans += 1
            else:
                ans -= 1

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    operations1 = ["--X", "X++", "X++"]
    result1 = solution.finalValueAfterOperations(operations1)
    print(result1)

    # test cases 2
    operations2 = ["++X", "++X", "X++"]
    result2 = solution.finalValueAfterOperations(operations2)
    print(result2)

    # test cases 3
    operations3 = ["X++", "++X", "--X", "X--"]
    result3 = solution.finalValueAfterOperations(operations3)
    print(result3)
    
    