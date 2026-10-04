from typing import List, Optional


class Solution:
    def reverseDegree(self, s: str) -> int:
        degree = 0

        for i in range(len(s)):
            rev = 26 - (ord(s[i]) - ord('a') + 1) + 1
            degree += (rev * (i + 1))

        return degree


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "abc"
    result1 = solution.reverseDegree(s1)
    print(result1)

    # test cases 2
    s2 = "zaza"
    result2 = solution.reverseDegree(s2)
    print(result2)
    