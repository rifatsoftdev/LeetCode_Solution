from typing import List, Optional


class Solution:
    def countCommas(self, n: int) -> int:
        ans = n - 999

        if ans < 0:
            return 0

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    n1 = 1002;
    result1 = solution.countCommas(n1);
    print(result1)

    # test cases 2
    n2 = 999;
    result2 = solution.countCommas(n2);
    print(result2)
    
    