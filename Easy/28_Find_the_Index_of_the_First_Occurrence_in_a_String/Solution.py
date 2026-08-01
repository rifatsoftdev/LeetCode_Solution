from typing import List, Optional


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        haystack_length = len(haystack)
        needle_length = len(needle)

        if needle_length == 0:
            return 0
        if haystack_length < needle_length:
            return -1

        for i in range(haystack_length - needle_length + 1):
            j = 0
            while j < needle_length and haystack[i + j] == needle[j]:
                j += 1
            if j == needle_length:
                return i

        return -1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.strStr("sadbutsad", "sad"))  # Output: 0

    # test cases 2
    print(solution.strStr("leetcode", "leeto"))  # Output: -1