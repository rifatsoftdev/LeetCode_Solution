from typing import List, Optional


class Solution:
    def firstMatchingIndex(self, s: str) -> int:
        left = 0;
        right = len(s) - 1;

        while (left <= right):
            if (s[left] == s[right]):
                return left;

            left += 1;
            right -= 1;

        return -1;


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "abcacbd";
    print(solution.firstMatchingIndex(s1));

    # test cases 2
    s2 = "abc";
    print(solution.firstMatchingIndex(s2));

    # test cases 3
    s3 = "abcdab";
    print(solution.firstMatchingIndex(s3));