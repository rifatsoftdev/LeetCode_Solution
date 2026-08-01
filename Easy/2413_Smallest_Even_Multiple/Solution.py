from typing import List, Optional


class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        if n % 2 == 0:
            return n
            
        return n * 2


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.smallestEvenMultiple(5))  # Expected: 10
    
    # test cases 2
    print(solution.smallestEvenMultiple(6))  # Expected: 6