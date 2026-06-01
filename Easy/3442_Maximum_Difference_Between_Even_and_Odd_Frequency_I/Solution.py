from typing import List, Optional


class Solution:
    def maxDifference(self, s: str) -> int:
        freq = {}

        for i in s:
            freq[i] = freq.get(i, 0) + 1

        odd_freq = []
        even_freq = []

        for count in freq.values():
            if count % 2 == 0:
                even_freq.append(count)
            else:
                odd_freq.append(count)

        return max(odd_freq) - min(even_freq)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "aaaaabbc"
    print(solution.maxDifference(s1))  # Output: 3
    
    # test cases 2
    s2 = "abcabcab"
    print(solution.maxDifference(s2))  # Output: 1
    
    