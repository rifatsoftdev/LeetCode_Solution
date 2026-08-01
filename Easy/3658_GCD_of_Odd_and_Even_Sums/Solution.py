from typing import List, Optional


class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        oddSum = 0
        evenSum = 0

        for i in range(1, n * 2 + 1, 2):
            oddSum += i

        for i in range(2, n * 2 + 1, 2):
            evenSum += i

        while evenSum != 0:
            oddSum, evenSum = evenSum, oddSum % evenSum

        return oddSum


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.gcdOfOddEvenSums(4))
    
    # test cases 2
    print(solution.gcdOfOddEvenSums(5))