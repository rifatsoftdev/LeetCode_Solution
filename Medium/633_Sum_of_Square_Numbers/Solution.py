from typing import List, Optional
from math import sqrt


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        left = 0
        right = int(sqrt(c))

        while left <= right:
            sum = left * left + right * right
            if sum == c:
                return True
            elif sum < c:
                left += 1
            else:
                right -= 1
        
        return False


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.judgeSquareSum(5))   # true
    
    # test cases 2
    print(solution.judgeSquareSum(3))   # false