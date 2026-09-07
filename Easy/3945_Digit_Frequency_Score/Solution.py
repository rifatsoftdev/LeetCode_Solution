from typing import List, Optional


class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        ans = 0

        while (n != 0):
            d = n % 10
            ans += d
            n //= 10

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.digitFrequencyScore(122))

    # test cases 2
    print(solution.digitFrequencyScore(101))
    