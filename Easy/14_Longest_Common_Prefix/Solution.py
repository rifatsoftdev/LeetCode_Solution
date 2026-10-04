from typing import List, Optional


class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if (not strs) or (len(strs) == 0):
            return ""

        strs.sort()
        first = strs[0]
        last = strs[-1]
        i = 0

        while i < len(first) and i < len(last) and first[i] == last[i]:
            i += 1

        return first[:i]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    strs1 = ["flower","flow","flight"]
    print(solution.longestCommonPrefix(strs1))  # Output: "fl"

    # test cases 2
    strs2 = ["dog","racecar","car"]
    print(solution.longestCommonPrefix(strs2))  # Output: ""