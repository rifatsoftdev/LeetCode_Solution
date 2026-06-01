import string
from typing import List, Optional

from Cython import char


class Solution:
    def makeGood(self, s: str) -> str:
        n = len(s)
        stack: List[char] = []

        for i in range(n):
            if stack:
                top = stack[-1]

                if (abs(ord(s[i]) - ord(top)) == 32):
                    stack.pop()
                else:
                    stack.append(s[i])
            else:
                stack.append(s[i])

        ans = ""

        while stack:
            c = stack.pop()
            ans = c + ans

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.makeGood("leEeetcode"))  # "leetcode"

    # test cases 2
    print(solution.makeGood("abBAcC"))  # ""

    # test cases 3
    print(solution.makeGood("s"))  # "s"