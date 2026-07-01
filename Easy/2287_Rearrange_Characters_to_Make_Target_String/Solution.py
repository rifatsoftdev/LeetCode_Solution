from typing import List, Optional


class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        freq_s = [0] * 26
        freq_t = [0] * 26

        for c in s:
            freq_s[ord(c) - ord('a')] += 1

        for c in target:
            freq_t[ord(c) - ord('a')] += 1

        min_num = float('inf')

        for i in range(26):
            if freq_t[i] > 0:
                min_num = min(min_num, freq_s[i] // freq_t[i])

        return min_num


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "ilovecodingonleetcode"
    target1 = "code"
    print(solution.rearrangeCharacters(s1, target1))

    # test cases 2
    s2 = "abcba"
    target2 = "abc"
    print(solution.rearrangeCharacters(s2, target2))

    # test cases 3
    s3 = "abbaccaddaeea"
    target3 = "aaaaa"
    print(solution.rearrangeCharacters(s3, target3))
    
    